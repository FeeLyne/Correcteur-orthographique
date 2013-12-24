	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <assert.h>	

	#include "mot.h"
	#include "unefile.h"
	#include "dictionnaire.h"
	#include "correcteur.h"
	
	#define LONGUEURMAXCHAINE = 260
	#define LONGUEURMAXMOT = 50

void decomposerChaineDeCaractere ( const char* ch, uneFile chDecomposee, uneFile positions);

	int main ( int argc , char * argv[] ) {
	}

void corrigerChaineDeCaractere (dictionnaire dico, correcteur * corr,uneFile chDecomposee, uneFile propositions, uneFile positions) {
	uneFile fileMot = creerUneFile();
	mot motAcorriger = (mot)malloc(sizeof(mot)*LONGUEURMAXMOT);
	propositions = creerUneFile();
	decomposerChaineDeCaractere(ch,chDecomposee,positions);
	uneFile.copier(chDecomposee,fileMot);
	while(!=uneFile.estVide(fileMot)){
		mot.copier(uneFile.obtenirElement(fileMot),motACorriger);
		uneFile.enfiler(propositions,rechercherPropositions(corr,motACorriger,dictionnaire));
	}
	uneFile.supprimer(fileMot);
	mot.supprimer(motAcorriger);
}

void decomposerChaineDeCaractere ( const char* ch, uneFile chDecomposee, uneFile positions) {
	char * temp = malloc (sizeof (*temp) * LONGUEURMAXCHAINE);
	int i = 0;
	chDecomposee=creerUneFile();
	positions=creerUneFile();
	while(i<=strlen(ch)){
		temp[0]='\0';
		while(!estUnSeparateur(ch[i]) && i<=strlen(ch)){
			if(estUneLettre(ch[i])){
				int longueur strlen(temp);
				temp[longueur]=ch[i];
				temp[longueur+1]='\0';		
			}
			i=i+1;
		}
		if(temp[0]!='\0'){
			uneFile.enfiler(chDecomposee,mot(temp));
			uneFile.enfiler(positions,i+1-strlen(temp));
		}
		i=i+1;
	}
}



void completerDictionnaire (dictionnaire dico, uneFile fileMot) {
	while(!estVide(uneFile)){
		mot temp=(mot)malloc(sizeof(mot)*LONGUEURMAXMOT)
		temp=uneFile.obtenirElement(uneFile);
		dictionnaire.inserer(dico,temp);
		defiler(uneFile);
		free(temp);
	}
}

uneFile decomposerFichierTexte (FILE * texte) {
	uneFile fileTemp=creerUneFile();
	char * chaineTemp=(char)malloc(sizeof(char)*LONGUEURMAXCHAINE)
	while(!=feof(texte)){
		fgets(chaineTemp,LONGUEURMAXMOT,texte);
		enfiler(fileTemp,mot(chaineTemp));
	}
	free(chaineTemp);
	return fileTemp;
}
