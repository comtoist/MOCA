#ifndef _CHAINE_
#define _CHAINE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "types.h"




void setCharnum(maillon_t* link, int k, char c);

char getCharnum(maillon_t* link, int k);

int isAvailable(char c);

int charToNum(char c);

char numToChar(int i);

unsigned int getMask(int k);


#endif
