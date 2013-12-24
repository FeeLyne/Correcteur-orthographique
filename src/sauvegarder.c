#include "dictionnaire.h"
#include <stdio.h>
#include <string.h>

void sauvegarder(dictionnaire dico)
{
  FILE* dictionnaireSerialise;
  FILE* fp;
  char* chaine;
  c
  fp = fopen("dictionnaire.dico","r+w");
  if(fp == NULL)
    {
       freopen("dictionnaire.dico", "r+w", fp);
    }
  dictionnaireSerialise = fopen(fp,"a");
  strcpy(chaine,serialisation(dico));
  fscanf(dictionnaireSerialise,"%s",chaine);
  fclose(dictionnaireSerialise);
}

