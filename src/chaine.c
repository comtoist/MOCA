
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "chaine.h"
#include "types.h"




void setCharnum(maillon_t* link, int k, char c) {
  if (link == NULL) {
    printf("setCharnum : link null\n");
  } else {
    link->elem = (link->elem & ~getMask(k)) + ((unsigned int)charToNum(c) << (5*(5-k)));
  }
}

char getCharnum(maillon_t* link, int k) {
  if (link == NULL) {
    printf("getCharnum : link null\n");
    return '#';
  } else {
    return numToChar((link->elem & getMask(k)) >> (5*(5-k)));
  }
}

int isAvailable(char c) {
  if (c < 'a' || c > 'z') {
    return 0;
  } else {
    return 1;
  }
}

int charToNum(char c) {
  return c - 'a' + 1;
}

char numToChar(int i) {
  return (i + 'a' - 1);
}

unsigned int getMask(int k) {
  switch(k) {
  case 0:
    return 0x3E000000;
    break;
  case 1:
    return 0x01F00000;
    break;
  case 2:
    return 0x000F8000;
    break;
  case 3:
    return 0x00007C00;
    break;
  case 4:
    return 0x000003E0;
    break;
  case 5:
    return 0x0000001F;
    break;
  }
  return 0x00000000;
}
