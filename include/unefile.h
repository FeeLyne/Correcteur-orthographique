#ifndef __UNEFILE__
#define __UNEFILE__

typedef struct noeudFile* uneFile;

uneFile creerUneFile(void);
void enfiler(uneFile* p_uneFile, void* p_Element);
void defiler(uneFile* p_uneFile);
void vider(uneFile* p_uneFile);
void* obtenirElement(uneFile* p_uneFile);
void* parcourirFile(uneFile* p_uneFile);
int estVide(uneFile* p_uneFile);
#endif
