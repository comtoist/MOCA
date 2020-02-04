#ifndef _DICO_
#define _DICO_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "types.h"
#include "maillon.h"

void insertDico(dico* dictionary, mot_t* linkWord);

void addToDico(dico* dictionary, char* word, unsigned int* line, unsigned int* colonne);

#endif
