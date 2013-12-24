#ifndef __CORRECTEUR__
#define __CORRECTEUR__

typedef uneFile (*correcteur)(mot,dictionnaire);

uneFile rechercherPropositions(correcteur p_fonctionCorrectrice, mot unMot, dictionnaire dico);
uneFile correcteurSimple(mot unMot, dictionnaire dico);
uneFile correctionParRemplacement(uneFile * f, mot unMot);
uneFile correctionSuppression(uneFile *f, mot unMot);
uneFile correctionParInsertion(uneFile *f, mot unMot);
uneFile correctionParInversion(uneFile *f, mot unMot);
#endif
