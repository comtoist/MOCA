#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "CuTest.h"
#include "maillon.h"
#include "types.h"
#include "dico.h"
char *StrToUpper (char *str){
  return str;
}

void PremierTestPourJouerAvecFrameworkCuTest (CuTest * tc){
  char *input = strdup ("hello world");
  char *actual = StrToUpper (input);
  char *expected = "HELLO WORLD";
  CuAssertStrEquals (tc, expected, actual);
}

void TestStringToMaillonMaillonToString(CuTest * tc){
  char* expected ="azertyuiopqsdfghjklmwxcvbn";
  maillon_t* STM = stringToMaillon(expected);
  char* actual = maillonToString(STM);
  CuAssertStrEquals(tc, expected,actual);
}

void TestGetSizeMaillon(CuTest * tc){
  char* mot = "hello";
  int expected = strlen(mot);//5 char
  maillon_t* STM = stringToMaillon(mot);
  int actual = getSizeMaillon(STM);
  CuAssertIntEquals(tc,expected,actual);

}

void TestCompareWord(CuTest* tc){
  unsigned int l=1;
  mot_t* mot1 = generateMot_t("hello",&l,&l);
  mot_t* mot2 = generateMot_t("hello",&l,&l);

  mot_t* motvide1 = generateMot_t("",&l,&l);
  mot_t* motvide2 = generateMot_t("",&l,&l);

mot_t* motpre1 = generateMot_t("hello world",&l,&l);
mot_t* motpre2 = generateMot_t("hello",&l,&l);

mot_t* motsuf1 = generateMot_t("hello world",&l,&l);
mot_t* motsuf2 = generateMot_t("world",&l,&l);

mot_t* motdiff1 = generateMot_t("sdfsdf",&l,&l);
mot_t* motdiff2 = generateMot_t("worldee",&l,&l);



mot_t* ptrnull = NULL;


int identique = compareWord(mot1,mot2);
int vide = compareWord(motvide1,motvide2);
int prefixe = compareWord(motpre1,motpre2);
int suffixe = compareWord(motsuf1,motsuf2);
int different = compareWord(motdiff1,motdiff2);
int pointeurNull = compareWord(ptrnull,ptrnull);
int pointeurNullEtMot1 = compareWord(mot1,ptrnull);
int pointeurNullEtMot2 = compareWord(ptrnull,mot2);


int alphabetique1sup2 = compareWord(motdiff1,motdiff2);
int alphabetique2sup1 = compareWord(motdiff2,motdiff1);


CuAssertIntEquals(tc,0,identique);
CuAssertIntEquals(tc,0,vide);
CuAssertIntEquals(tc,-1,prefixe);
CuAssertIntEquals(tc,-1,suffixe);
CuAssertIntEquals(tc,-1,different);
CuAssertIntEquals(tc,1,pointeurNull);
CuAssertIntEquals(tc,-1,pointeurNullEtMot1);
CuAssertIntEquals(tc,1,pointeurNullEtMot2);
CuAssertIntEquals(tc,-1,alphabetique1sup2);
CuAssertIntEquals(tc,1,alphabetique2sup1);






}


CuSuite *MaTestSuite (){
  CuSuite *suite = CuSuiteNew ();
  SUITE_ADD_TEST (suite, PremierTestPourJouerAvecFrameworkCuTest);
  SUITE_ADD_TEST (suite, TestStringToMaillonMaillonToString);
   SUITE_ADD_TEST (suite, TestGetSizeMaillon );
   SUITE_ADD_TEST(suite,TestCompareWord);
  return suite;
}



