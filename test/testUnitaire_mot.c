#include<stdio.h>
#include"CUnit/Basic.h"
#include<string.h>
#include "mot.h"

int init_suite_success(void) {
return 0;
}
int clean_suite_success(void) {
return 0;
}
void test_estUnMot(void){
  CU_ASSERT(estUnMot("Bonjour")==0);
}
/*void test_creerMot(void){
CU_ASSERT_TRUE();
}*/

int main(int argc , char** argv){
CU_pSuite pSuite = NULL;

/* initialisation du registre de tests */
if (CUE_SUCCESS != CU_initialize_registry())
return CU_get_error();

/* ajout d'une suite de test */
 pSuite = CU_add_suite("Tests", init_suite_success, clean_suite_success);
if (NULL == pSuite) {
CU_cleanup_registry() ;
return CU_get_error() ;
 }
/* Ajout des tests ` la suite de tests boite noire */
 if ((NULL == CU_add_test(pSuite, "Test estUnMot", test_estUnMot))
     /*|| (NULL == CU_add_test(pSuite, "PT ordonnee(PT point2D(1,2))==2", test ordonnee))*/
) {
CU_cleanup_registry() ;
return CU_get_error() ;
}

 /* Lancement des tests */
CU_basic_set_mode(CU_BRM_VERBOSE);
CU_basic_run_tests() ;
printf ("\n");
CU_basic_show_failures(CU_get_failure_list()) ;
printf ("\n\n");

/* Nettoyage du registre */
CU_cleanup_registry() ;
return CU_get_error() ;
}
