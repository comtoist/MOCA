#ifndef _MAILLON_
#define _MAILLON_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "chaine.h"
#include "types.h"


maillon_t* stringToMaillon(char* word);

int getSizeMaillon(maillon_t* link);

char* maillonToString(maillon_t* link);

int compareWord(mot_t* w1, mot_t* w2);

void addTailWord(dico* dictionary, mot_t* linkWord);

void addHeadWord(dico* dictionary, mot_t* linkWord);

void incWord(emplacement_t* location, unsigned int line, unsigned int colonne);

char *next_word(FILE *f, unsigned int *nblin, unsigned int *nbcol,char *separators ,
unsigned int current_line, unsigned int current_col);

#endif


