#include <stdio.h>
#include <string.h>
#include "dictionnaire.h"

dictionnaire charger(char* nomFichierDictionnaire) 
{
 char * chaine;
 dictionnaire res;
 FILE * fichier;
 
 res = dictionnaire();
 fichier = fopen(nomFichierDictionnaire, "r");
 if (fichier == NULL)
 {
   perror(nomFichierDicitonnaire);
 }
 else
 {
   fichier = fopen(nomFichierDictionnaire, "w");
   strcpy(chaine,getline(fichier));
   fclose(fichier);
   res = deserialisation(fichier);
 }
 return res;
}


