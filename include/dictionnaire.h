#ifndef __DICTIONNAIRE__
#define __DICTIONNAIRE__

typedef NoeudDictionnaire* dictionnaire ;

dictionnaire creerDictionnaire ();
int estVide (dictionnaire dico);
long int longueur (dictionnaire dico);
int estPresent (dictionnaire dico, mot unMot);
void supprimer (dictionnaire dico, mot unMot);
void inserer (dictionnaire dico, mot unMot);
dictionnaire deserialisation(FILE* fichier);
dictionnaire *sauvegarder(dictionnaire* dico);
char *serialisation(dictionnaire dico);
dictionnaire charger(char* nomFichierDictionnaire);
#endif
