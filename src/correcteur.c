#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mot.h"
#include "dictionnaire.h"
#include "correcteur.h"
#include "unefile.h"

uneFile rechercherPropositions(correcteur p_fonctionCorrectrice, mot unMot, dictionnaire dico)
{
<<<<<<< .mine
  return (*p_fonctionCorrectrice)(unMot,dico);
=======
  return (*p_fonctionCorrectrice)(unMot,dico);
>>>>>>> .r154
}

uneFile correcteurSimple(mot unMot, dictionnaire dico)
{
uneFile temp,prop;
mot essai[0]='\0';

temp=creerUneFile();
prop=creerUneFile();
correctionParRemplacement(temp,unMot);
correctionParSuppression(temp,unMot);
correctionParInsertion(temp,unMot);
correctionParInversion(temp,unMot);

while (!uneFile.estVide(temp))
	{
	essai=uneFile.obtenirElement(*temp);
	if(dictionnaire.estPresent(dico,essai))
		{
		uneFile.enfiler(prop, essai);
		}
	uneFile.defiler(temp);
	}
return prop;
}


uneFile correctionParRemplacement(uneFile * f, mot unMot)
{
int i;
char c;
mot temp[0]='\0';

 for(i=0;i<mot.longueur(unMot);i++)
	{
	for(c='a';c<='z';c++)
		{
		temp=mot.remplacerCaractere(unMot,i,c);
		uneFile.enfiler(f,temp);
		}
	}
return *f;
}

uneFile correctionSuppression(uneFile *f, mot unMot)
{
int i;
mot temp[0]='\0';

if(mot.longueur(unMot)>1)
	{

	for(i=0;i<mot.longueur(unMot);i++)
		{
		temp=mot.supprimerCaractere(unMot,i);
		uneFile.enfiler(f,temp);
		}
	}
return *f;
}

uneFile correctionParInsertion(uneFile *f, mot unMot)
{
int i;
char c;
mot temp[0]='\0';

for(i=0;i<mot.longueur(unMot);i++)
	{
	for(c='a';c<='z';c++)
		{
		temp=mot.insererCaractere(unMot,i,c);
		uneFile.enfiler(f,temp);
		}
	}
return *f;
}

uneFile correctionParInversion(uneFile *f, mot unMot)
{
int i;
mot temp[0]='\0';

if(mot.longueur(unMot)>1)
	{
	for(i=0;i<(mot.longueur(unMot)-1);i++)
		{
		temp=mot.inverserCarateres(unMot,i,i+1);
		uneFile.enfiler(f,temp);
		}
	}
return *f;
}
