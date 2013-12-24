#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "dictionnaire.h"

char *serialisation(dictionnaire dico){

 char pg = '(';
 char pd = ')';
 char [] pc = "()";
 char exlm = '!';
 char pu = '#';
 char* lettre;
 char* indicFinMot;
 char* res;

 dictionnaire niveauSuivant;
 dictionnaire noeudSuivant;

if (estVide(dico))
{
  strcpy(res,&pc);
}
else
{
  strcpy(lettre,obtenirLettre(dico)); 
  if (obtenirEstFinMot(dico))
  {
    strcpy(indicFinMot,&pu);
  else
    strcpy(indicFinMot,&exlm);
  }
}
if ((obtenirNoeudSuivant(dico)==NULL)&&(obtenirNiveauSuivant(dico)==NILL))
{
  strcpy(res,lettre);
  strcat(res,indicFinMot); 
 }
else
{
  niveauSuivant = obtenirNiveauSuivant(dico);
  noeudSuivant = obtenirNiveauSuivant(dico);
  strcpy(res,&pg);
  strcat(res,lettre);
  strcat(res,indiceFinMot);
  strcat(res,serialisation(niveauSuivant));
  strcat(res,serialisation(noeudSuivant));
  strcat(res,&pd);
 }
return res;
}
