#ifndef __MOT__
#define __MOT__

typedef char* mot;

mot motEnMinuscule(mot unMot);
mot creerMot (char* chaine);
int estUnMot (char* chaine);
int longueur (mot mot);
char iemeCaractere (mot unMot, int i);
void supprimerCaractere (mot* unMot, int position);
void insererCaractere (mot* unMot, int position, char c);
void remplacerCaractere (mot* unMot, int position, char c);
void inverserCaracteres (mot* unMot, int i, int j);
int egalite(mot Mot1, mot Mot2);
void copier(mot* Mot1, mot* Mot2);
#endif
