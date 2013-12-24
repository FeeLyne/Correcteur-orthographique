#include "dictionnaire.h"
#include <stdio.h>
#include <string.h>

dictionnaire deserialisation(FILE* dictionnaireSerialise)
{
 char pg = '(';
 char pd = ')';

 char c;
 dictionnaire niveauSuivant;
 dictionnaire noeudSuivant;
 dictionnaire dico;
 
 c = getc(dictionnaireSerialise);
 if (c==pg)
   {
     c = getc(dictionnaireSerialise)
    }
 if (c==pd)
   {
     retour NULL;
 else
   {
     deserialiserUnNoeud(c,dicitonnaireSerialise,dico);
     c = getc(dictionnaireSeialise);
     if (c==pg)
       {
	 fixerNoeudSuivant(&dico,deserialisation(dictionnaireSerialise));
       }
     else
       {
	 deserialiserUnNoeud(c,dictionnaireSerialise,niveauSuivant);
	 fixerNoeudSuivant(&dico,niveauSuivant);
       }
     c = getc(dictionnaireSerialise);
     if (c==pg)
       {
	 fixerNoeudSuivant(&dico,deserialisation(dictionnaireSerialiseno));
       }
     else
       {
	 deserialiserUnNoeud(c,dictionnaireSerialise,noeudSuivant);
	 fixerNoeudSuivant(&dico,noeudSuivant);
       }
     c = getc(dictionaireSerialise)
     return dico
   }
 }

static void deserialisationUnNoeud(char* chaine, char c, dictionnaire* dico)
{
  char lettre;
  char c;//??
  Bool estFinMot;
  NoeudDictionnaire noeud;

  lettre = c;
  c = getc(chaine);
  estFinMot = (c==pu);
  noeud = creerNoeud();
  dico = &noeud;
  fixerLettre(&dico,lettre);
  fixerEstFinMot(dico,estFinMot);
}
