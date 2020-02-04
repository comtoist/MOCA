#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "types.h"
#include "dico.h"

void insertDico(dico* dictionary, mot_t* linkWord) {
  dico* newDictionary = (dico*) malloc(sizeof(dico));
  dico* newDictionaryPrevious = (dico*) malloc(sizeof(dico));
  newDictionary = dictionary;
  newDictionaryPrevious = newDictionary;
  while(compareWord(newDictionary->mot,linkWord)<0 && newDictionary != NULL) {
    if (newDictionary->next == NULL) {
      addTailWord(newDictionary,linkWord);
      return;
    } else {
      newDictionaryPrevious = newDictionary;
      newDictionary = newDictionary->next;
    }
  }
  if (compareWord(newDictionary->mot,linkWord)==0) {
    incWord(newDictionary->mot->queue_liste,linkWord->tete_liste->line,linkWord->tete_liste->colonne);
  } else { //
    if (newDictionary == dictionary) {
      addHeadWord(newDictionary,linkWord);
    } else {
      addTailWord(newDictionaryPrevious,linkWord);
    }
  }
}

void addToDico(dico* dictionary, char* word, unsigned int* line, unsigned int* colonne) {
  mot_t* newLinkWord = (mot_t*) malloc(sizeof(mot_t));
  emplacement_t* location = (emplacement_t*) malloc(sizeof(emplacement_t));
  newLinkWord->tete_mot = stringToMaillon(word);
  newLinkWord->queue_mot = newLinkWord->tete_mot;
  location->line = *line;
  location -> colonne = *colonne;
  newLinkWord->tete_liste = location;
  newLinkWord->queue_liste = location;
  if (dictionary == NULL) {
    dico* newDictionary = (dico*) malloc(sizeof(dico));
    newDictionary->mot = newLinkWord;
    newDictionary->next = NULL;
    dictionary = newDictionary;
  } else if (dictionary->mot == NULL) {
    dictionary->mot = newLinkWord;
  } else {
    insertDico(dictionary,newLinkWord);
  }
}
