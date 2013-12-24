#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* pour utiliser les fonctions sur les chaines de caracteres*/
#include <ctype.h>
#include <assert.h>

#include "mot.h"

#define NDEBUG

/* PARTIE PRIVEE */
static int estUneLettre(char c){
  return (((c>'a') && (c<'z')) || ((c>'é') && (c<'î')) || (c='ô') || (c='ù'));
}

void supprimerCaractereChaine(char* chaine,int position){
  char* chainetemp=(char*)malloc(strlen(chaine)*sizeof(char*));
 int i;
  chainetemp=strncat(chainetemp,chaine,position-2);
  for(i=position;i<strlen(chaine);i++){
    chainetemp=strcat(chainetemp,chaine);
  }
  chaine=chainetemp;
}

/* PARTIE PUBLIQUE */
mot motEnMinuscule(mot unMot){
   mot motSortie;
   int i;
   motSortie = (mot)malloc(sizeof(mot)*(longueur(unMot)+1));
         for(i=0;unMot[i];i++){
            motSortie[i]=tolower(unMot[i]);
         }
         motSortie[i]='\0';
   return motSortie;
}

mot creerMot (char* chaine){
  int i;
  if (estUnMot(chaine))
    return chaine;
  else
    for(i=0;i<strlen(chaine);i++){
      if(!estUneLettre(iemeCaractere(chaine,i))){
	supprimerCaractereChaine(chaine,i);
      }
    }
  return chaine;
}

int estUnMot (char* chaine){
  int estLettre, i;
  char c;
  estLettre=1;
  i=1;
  while (estLettre && i<=strlen(chaine)){
    c=chaine[i];
    if(estUneLettre(c))
      i=i+1;
    else
      estLettre=0;
  }
  return estLettre;
}

int longueur (mot chaine){
  return strlen(chaine);
}

char iemeCaractere (mot unMot, int i){
  return unMot[i];
}

void supprimerCaractere (mot* unMot, int position){
  char* chaine = (char*)malloc(longueur(*unMot)*sizeof(char*));
  int i;
  chaine="";
  chaine=strncat(chaine,*unMot,position-2);
  for(i=position;i<longueur(*unMot);i++){
    chaine=strcat(chaine,*unMot);
  }
  *unMot=chaine;
}

void insererCaractere (mot* unMot, int position, char c){
  char* chaine = (char*)malloc((longueur(*unMot)+2)*sizeof(char*)); /* taille de la chaine +1 char sup et un d'arret */ 
  char temp[2];
  int i;
  chaine=strncat(chaine,*unMot,position-2);
  temp[0]=c; /* temp[] permet de transformer un char en char* */
  temp[1]='\0'; /* \0 annonce la fin d'une CdC */
  chaine=strcat(chaine,temp);
  if(strlen(chaine)!=longueur(*unMot)){
    for(i=position;i<=longueur(*unMot);i++){
      temp[0]=iemeCaractere(*unMot,i);
      temp[1]='\0';
      chaine=strcat(chaine,temp);
    }
  }
  *unMot=chaine;
}

void remplacerCaractere (mot* unMot, int position, char c){
  char* chaine = (char*)malloc((longueur(*unMot)+1)*sizeof(char*));
  char temp[2];
  int i;
  /* A corriger */
  chaine=strncat(chaine,*unMot,position-2);
  temp[0]=c;
  temp[1]='\0';
  chaine=strcat(chaine,temp);
  for(i=position;i<longueur(*unMot);i++){
    temp[0]=iemeCaractere(*unMot,i);
    temp[1]='\0';
      chaine=strcat(chaine,temp);
  }
  creerMot(chaine);
}

void inverserCaracteres (mot* unMot, int i, int j){
  char temp1,temp2;
  temp1=iemeCaractere(*unMot,i);
  temp2=iemeCaractere(*unMot,j);
  supprimerCaractere(unMot,i);
  supprimerCaractere(unMot,j);
  insererCaractere(unMot,i,temp2);
  insererCaractere(unMot,j,temp1);
}

int egalite(mot Mot1, mot Mot2){
  int i, estEgal;
  estEgal=1;
  if(longueur(Mot1)!=longueur(Mot2)){
    estEgal=0;
  }
  else{
    i=0;
    while(estEgal && i<longueur(Mot1)){
      if(iemeCaractere(Mot1,i)!=iemeCaractere(Mot2,i)){
      estEgal=0;
      }
      else{
	i=i+1;
      }
    }
  }
  return estEgal;
}

void copier(mot* Mot1, mot* Mot2){
  int i;
  Mot2=malloc(longueur(*Mot1)*sizeof(mot));
  for(i=0;longueur(*Mot1);i++){
    *Mot2[i]=*Mot1[i];
  }
}
