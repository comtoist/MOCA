#ifndef _AFFICHAGE_
#define _AFFICHAGE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "maillon.h"
#include "types.h"

void displayWord(mot_t* word, FILE *filedes);

void displayDico(dico* dictionary);

#endif
