#include <stdio.h>
#include <string.h>
#include "dictionnaire.h"
#include "CUnit/Basic.h"

static FILE* temp_file = NULL;
static FILE* temp_file1 = NULL;  
static FILE* temp_file2 = NULL;
static dictionnaire dico= NULL;
static NoeudDictionnaire nd2;
  nd2.Element = a;
  nd2.NoeudSuivant = NULL;
  nu2.NiveauSuivant = NULL;
  nu2.estFinMot = 1; 

static NoeudDictionnaire nd1;
  nd1.Element = b;
  nd1.NoeudSuivaNt = NULL;
  nu1.NiveauSuivant = &nd2;
  nu1.estFinMot = 0;
/*on met "(a#)" dans temp1.txt*/
/*on met "(b!a#())" dans temp2.txt*/
int init_suite1(void)
{
   if (NULL == (temp_file1 = fopen("temp1.txt", "w+"))) {
      return -1;
   }
   else {
      return 0;
   }
}
int init_suite1(void)
{
   if (NULL == (temp_file2 = fopen("temp2.txt", "w+"))) {
      return -1;
   }
   else {
      return 0;
   }
}

int clean_suite1(void)
{
   if (0 != fclose(temp_file)) {
      return -1;
   }
   else {
      temp_file = NULL;
      return 0;
   }
}

void testSerialisation(void)
{ 
  CU_ASSERT("()" == serialisation(dico));
  CU_ASSERT("(a#)" == serialisation(&nd2));
  CU_ASSERT("(b!a#())" == serialisation(&nd1));
}


void testDeserialisation(void)
{
  CU_ASSERT(dico == deserialisation(temp_file));
  CU_ASSERT(&nd2 == deserialisation(temp_file1));
  CU_ASSERT(&nd1 == deserialisation(temp_file2));
}

void testCharger(void)
{
  char* ch1="temp_file1.txt";
  char* ch2="temp_file1.txt";
  CU_ASSERT(&nd2 ==charger(temp_file1));
  CU_ASSERT(&nd1 == charger(temp_file2));
}

void testSauvegarder(void)
{
  /*En train de chercher une solution (besion d'aide)*/
}


int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if ((NULL == CU_add_test(pSuite, "test of serialisation()", testSerialisation)) ||
       (NULL == CU_add_test(pSuite, "test of deserialisation()", testDeserialisation)) ||
       (NULL == CU_add_test(pSuite, "test of charger()", testCharger))
       ||  (NULL == CU_add_test(pSuite, "test of sauvegarder()", testSauvegarder)))

)
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
