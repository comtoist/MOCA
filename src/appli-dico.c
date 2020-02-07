
#include "affichage.h"

#include "dico.h"

#include "CuTest.h"
#include "AllTests.h"

#define FINAL 0

char *separators = SEP;
unsigned int current_line=1;
unsigned int current_col=1;

int maindico(int argc, char* argv[]){
 if(argc != 2){
    fprintf(stderr, "Il faut un nom de fichier texte\n");
    exit(BADARGNUMBER);
  }

  FILE* f = fopen(argv[1], "r");
  if(f == NULL){
    fprintf(stderr, "bad entry file \n");
    exit(OPENFILEERROR);
  }

  unsigned int* line = (unsigned int*) malloc(sizeof(int));
  unsigned int* colonne = (unsigned int*) malloc(sizeof(int));
  char* word = (char*) malloc(sizeof(char)*maxSizeWord);
  dico* dictionary = (dico*) malloc(sizeof(dico));
  while(!feof(f)) {
    word = next_word(f,line,colonne,separators,current_line,current_col);
    addToDico(dictionary,word,line,colonne);
  }
  displayDico(dictionary);
  fclose(f);
  return 0;
}

int main(int argc, char* argv[])
{
  #if FINAL
    maindico(argc,argv);

  #else
    RunAllTests();
  #endif
  return 0;
}
