#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionnaire.h"
#include "mot.h"

typedef struct NoeudDictionnaire{
char lettre;
NoeudDictionnaire* NoeudSuivant;
NoeudDictionnaire* NiveauSuivant;
int estFinMot;
} NoeudDictionnaire;

NoeudDictionnaire* creerNoeud (char lettre, NoeudDictionnaire* noeudSuivant, NoeudDictionnaire* niveauSuivant,int estFinMot){
NoeudDictionnaire noeudTemp = malloc(sizeof(NoeudDictionnaire));
noeudTemp.lettre = lettre;
noeudTemp.noeudSuivant = noeudSuivant;
noeudTemp.niveauSuivant = niveauSuivant;
noeudTemp.estFinMot = estFinMot;
return (&noeudTemp);
}

char obtenirLettre (dictionnaire dico){
    return (dico)->lettre;
}

dictionnaire obtenirNoeudSuivant (dictionnaire dico){
    return (dico)->noeudSuivant;
}

dictionnaire obtenirNiveauSuivant (dictionnaire dico){
    return (dico)->niveauSuivant;
}

int obtenirEstFinMot (dictionnaire dico){
    return (dico)->estFinMot;
}

void fixerLettre (dictionnaire* p_dico, char lettre){
(*p_dico)->lettre=lettre;
}

void fixerNoeudSuivant (dictionnaire* p_dico, dictionnaire* p_noeudSuivant){
(*p_dico)->noeudSuivant=*p_noeudSuivant;
}

void fixerNiveauSuivant (dictionnaire* p_dico, dictionnaire* p_niveauSuivant){
(*p_dico)->niveauSuivant=*p_niveauSuivant;
}

void fixerEstFinMot (dictionnaire* p_dico, int estFinMot){
(*p_dico)->estFinMot=estFinMot;
}

dictionnaire creerDictionnaire (){
return NULL;
}

int estVide (dictionnaire dico){
    return (dico == NULL);
}

long int hauteur (dictionnaire dico){
long int h;
if (estVide(dico)){
	h=0;
	}else{
    dictionnaire noeudSuivant=obtenirNoeudSuivant(dico);
    dictionnaire niveauSuivant=obtenirNiveauSuivant(dico);
		h=1+max(hauteur(noeudSuivant),hauteur(niveauSuivant));}
return h;
}

int estPresent (dictionnaire dico, mot motAVerifier){
        int present;
        mot unMot;
        copier(motAVerifier,unMot);
        if (estVide(dico)){
                present=0;}
        else{
                if (iemeCaractere(unMot,1)==obtenirLettre(dico)){
                        if (longueur(unMot)==1){
                                if (obtenirEstFinMot(dico)){
                                        present=1;}
                                else{
                                        present=0;}}
                        else{
                            mot unMotTemp;
                            copier(&unMot,&unMotTemp);
                            supprimerCaractere(&unMotTemp,1);
                            dictionnaire niveauSuivant=(dico)->niveauSuivant;
                            present=estPresent(niveauSuivant,unMotTemp);}}
                else{
                       dictionnaire noeudSuivant=(dico)->noeudSuivant;
                       present=estPresent(noeudSuivant,unMot);}}
        return (present);
}

void supprimer (dictionnaire dico, mot unMot){
dictionnaire temp;
int i;
motEnMinuscule(unMot);
dictionnaire temp=dico;
for(i=0;i<longueur(unMot);i++){
	while(temp.lettre!=iemeCaractere(unMot,i)){
		temp=temp.noeudSuivant;
		}
	if (i!=longueur(unMot)){
		temp=temp.niveauSuivant;
		}
	}
temp.estFinMot=0;
}

void inserer (dictionnaire dico, mot unMot){
dictionnaire temp1, temp2;
NoeudDictionnaire n;
int i;
motEnMinuscule(unMot);
n=creerNoeud(iemeCaractere(unMot,1), NULL, NULL, 0);
if (estVide(dico)){
	dico=&n;
	}
temp1=dico;
for(i=0;i<longueur(mot);i++){
	n=creerNoeud(iemeCaractere(unMot,1), NULL, NULL, 0);
	while(iemeCaractere(unMot,i)!=obtenirLettre(temp1)){
		if(estVide(temp1)){
			temp1=&n;
			}else{
				if(obtenirNoeudSuivant(temp1)!=NULL && obtenirLettre(obtenirNoeudSuivant(temp1))<=obtenirLettre(temp1)){
					temp1=obtenirNoeudSuivant(temp1);
					}else{
						temp2=obtenirNoeudSuivant(temp1);
						temp1.NoeudSuivant=&n;
						n.NoeudSuivant=temp2;
						temp1=obtenirNiveauSuivant(temp1);
						}
				}
		}
	temp=obtenirNiveauSuivant(temp);
	}
temp.estFinMot=1;
}
