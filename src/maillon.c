
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "maillon.h"
#include "types.h"





maillon_t* stringToMaillon(char* word) {
  if (word == NULL) {
    return NULL;
  } else {
    maillon_t* useLink = (maillon_t*) malloc(sizeof(maillon_t));
    useLink->elem = 0;
    useLink->next = NULL;
    maillon_t* savLink = useLink;
    int i;
    for(i=0;i<strlen(word);i++) {
      if ((i % 6) == 0 && useLink->elem != 0) {
        maillon_t* newLink = (maillon_t*) malloc(sizeof(maillon_t));
        newLink->elem = 0;
        newLink->next = NULL;
        useLink->next = newLink;
        useLink = newLink;
      }
      setCharnum(useLink,(i%6),word[i]);
    }
    
    return savLink;
  }
}

int getSizeMaillon(maillon_t* link) {
  if (link == NULL) {
    return 0;
  } else {
    int i = 0,res = 0;
    maillon_t* useLink = link;
    while(useLink != NULL) {
      for(i=0;i<=5;i++) {
	if  (isAvailable(getCharnum(useLink,i)) == 0) {break;}
	res++;
      }
      useLink = useLink->next;
    }
    free(useLink);
    return res;
  }
}

char* maillonToString(maillon_t* link) {
  if (link == NULL) {
    return NULL;
  } else {
    char* word = (char*) malloc(sizeof(char)*getSizeMaillon(link)+1);
    maillon_t* useLink = link;
    int index = 0, i = 0;
    while (useLink != NULL) {
      for(i=0;i<=5;i++) {
        if (isAvailable(getCharnum(useLink,i)) == 0) {break;}
        else {
          word[index] = getCharnum(useLink,i);
          index++;
        }
      }
      
      useLink = useLink->next;
    
    }
    word[index] = '\0';
    free(useLink);
    return word;
  }
}

int compareWord(mot_t* w1, mot_t* w2) {
  if (w1 == NULL) {
    return 1;
  } else if (w2 == NULL) {
    return -1;
  } else {
    char* word1 = maillonToString(w1->tete_mot);
    char* word2 = maillonToString(w2->tete_mot);
    int minSize = (strlen(word1)<strlen(word2))?strlen(word1):strlen(word2);
    int i = 0;
    int pos = 0;
    while(i<minSize && pos == 0) {
      pos = (word1[i]<word2[i])?-1:(word1[i]>word2[i])?1:0;
      i++;
    }
    return (pos == 0 && strlen(word1) < strlen(word2))?-1:(pos == 0 && strlen(word1) > strlen(word2))?1:pos;
  }
}

void addTailWord(dico* dictionary, mot_t* linkWord) {
  dico* newDictionary = (dico*) malloc(sizeof(dico));
  newDictionary->mot = linkWord;
  newDictionary->next = NULL;
  if(dictionary->next == NULL) {
    dictionary->next = newDictionary;
  } else {
    newDictionary->next = dictionary->next;
    dictionary->next = newDictionary;
  }
}

void addHeadWord(dico* dictionary, mot_t* linkWord) {
  dico* newDictionary = (dico*) malloc(sizeof(dico));
  newDictionary->mot = linkWord;
  newDictionary->next = dictionary;
  dictionary = newDictionary;
}

void incWord(emplacement_t* location, unsigned int line, unsigned int colonne) {
  emplacement_t* newLocation = (emplacement_t*) malloc(sizeof(emplacement_t));
  emplacement_t* tempLocation = (emplacement_t*) malloc(sizeof(emplacement_t));
  tempLocation = location;
  newLocation->next = NULL;
  newLocation->line = line;
  newLocation->colonne = colonne;
  while(tempLocation->next != NULL) {
    tempLocation = tempLocation->next;
  }
  tempLocation->next = newLocation;
}

char *next_word(FILE *f, unsigned int *nblin, unsigned int *nbcol,char *separators ,
unsigned int current_line, unsigned int current_col){
  char s[100];
  char *res;
  unsigned int i=0, startl = current_line, startc = current_col;
  char sep;
  sep = fgetc(f);
  while ((strchr(separators,sep) == NULL  || sep == '\n') && !feof(f)) {
  printf("%c ",sep);
    printf(" %d\n",startc);
    startc++;
    if (sep == '\n'){
      startl++; startc = 1;
    }
    // #ifdef KLEE
    // read_int();
    // #else
     sep = fgetc(f);
    // #endif
  }
  ungetc(sep,f);
  
  if (nblin != NULL) *nblin = startl;
  if (nbcol != NULL) *nbcol = startc;
  while (((strchr(separators, s[i]=fgetc(f)) == NULL) && s[i] != '\n')&& !feof(f)){
    printf("%c",s[i]);
    i++; startc++;
  }
  sep = s[i];
  s[i] = '\0';
  res = (char *)malloc(strlen(s)+1);
  strcpy(res,s);
  while (strchr(separators,sep) != NULL  || sep == '\n' ) {
    startc++;
    if (sep == '\n'){
      startl++; startc = 1;
    }
    sep = fgetc(f);
  }
  ungetc(sep,f);
  current_line = startl;
  current_col = startc;

  printf("col :%d \n",current_col);
    printf("lig :%d ",current_line);
  *nbcol=current_col;
  *nblin=current_line;
  return res;
}

void freeMaillon(maillon_t* maillon){
  maillon_t* sauv;
  while(maillon != NULL){
    sauv = maillon;
    maillon=maillon->next;
    free(sauv);
  }

}