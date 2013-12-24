#include <stdio.h>
#include <stdlib.h>
#include "unefile.h"

typedef struct noeudFile{
 	struct noeudFile* prec;
 	struct noeudFile* suiv;
	void* Element;
} noeudFile;

static void file_debut(uneFile* p_uneFile);
static void file_prec(uneFile* p_uneFile);
static void file_fin(uneFile* p_uneFile);
static void file_suiv(uneFile* p_uneFile);
uneFile creerUneFile (void);
void enfiler(uneFile* p_uneFile, void* Element);
void defiler(uneFile* p_uneFile);
void vider(uneFile* p_UneFile);
void* obtenirElement(uneFile* p_uneFile);
void* parcourirFile(uneFile* p_uneFile);

uneFile creerUneFile(void){
	return (NULL);
}

static void file_debut(uneFile* p_uneFile){
   if (p_uneFile != NULL && *p_uneFile != NULL)
   {
      while ((*p_uneFile)->prec != NULL){
         file_prec(p_uneFile);}
   }
   return;
}

static void file_prec(uneFile* p_uneFile){
   if (p_uneFile != NULL && *p_uneFile != NULL)
      *p_uneFile = (*p_uneFile)->prec;
   return;
}

static void file_fin(uneFile* p_uneFile){
   if (p_uneFile != NULL && *p_uneFile != NULL)
   {
      while ((*p_uneFile)->suiv != NULL)
         file_suiv (p_uneFile);
   }
   return;
}

static void file_suiv(uneFile* p_uneFile){
   if (p_uneFile != NULL && *p_uneFile != NULL)
      *p_uneFile = (*p_uneFile)->suiv;
   return;
}


void* obtenirElement(uneFile* p_uneFile){
	file_fin(p_uneFile);  
	return (*p_uneFile)->Element;
}


void enfiler (uneFile* p_uneFile, void* Element)
{
   if (p_uneFile != NULL)
   {
      uneFile fileCourrante = creerUneFile();
      uneFile filePrecedente = creerUneFile();

      file_debut (p_uneFile);
      fileCourrante = *p_uneFile;
      filePrecedente = malloc (sizeof (*filePrecedente));
      if (filePrecedente != NULL)
      {
         (filePrecedente)->Element = Element;
         (filePrecedente)->suiv = fileCourrante;
         (filePrecedente)->prec = NULL;
         if (fileCourrante != NULL){
            	(fileCourrante)->prec = filePrecedente;
		(filePrecedente)->suiv = fileCourrante;}
         	*p_uneFile = filePrecedente;
      }
      else
      {
         fprintf (stderr, "Memoire insuffisante\n");
         exit (EXIT_FAILURE);
      }
   }
   return;
}

void defiler (uneFile* p_uneFile)
{
   if (p_uneFile != NULL && *p_uneFile != NULL)
   {
      uneFile fileCourrante = creerUneFile();
      uneFile filePrecedente = creerUneFile();

      file_fin (p_uneFile);
      fileCourrante = *p_uneFile;
      if (fileCourrante != NULL)
         filePrecedente = fileCourrante->prec;
      free(fileCourrante);
      if (filePrecedente != NULL)
         filePrecedente->suiv = NULL;
      *p_uneFile = filePrecedente;
   }
}


void vider(uneFile* p_uneFile)
{
   if (p_uneFile != NULL && *p_uneFile != NULL)
   	{
      	while (*p_uneFile != NULL)
        	defiler (p_uneFile);
   	}   
	return;
}


void* parcourirFile (uneFile* p_fileACopier){
 	if (p_fileACopier != NULL && *p_fileACopier != NULL){
		void* temp = obtenirElement(p_fileACopier);	
		if((*p_fileACopier)->prec != NULL){
			file_prec(p_fileACopier);
			}
		return temp;	
	}
	else {
		fprintf (stderr, "Erreur pointeur sur file ou file vide\n");
         	exit (EXIT_FAILURE);
	}
}

int estVide(uneFile* p_uneFile){
    if (p_uneFile != NULL){
        return (*p_uneFile==NULL);}
    else {
        fprintf (stderr, "Erreur pointeur sur file vide\n");
        exit (EXIT_FAILURE);}            
}