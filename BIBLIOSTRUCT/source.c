#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Biblio.h>
/*                                Pile                 */
Pile InitialiserPile()
{
return NULL; 
}
int EstPileVide(Pile P)
{
/* renvoie 1 si la liste est vide */
return (P == NULL) ? 1 : 0;
}
int EstPilePleine(Pile P)
{
    return 0;
}
int AccederSommet(Pile P, TypeDonnee *pelem)
{
if (EstPileVide(P))
return 1; /* on retourne un code d’erreur */
*pelem = P->donnee; /* on renvoie l’élément */
return 0;
}
void Empiler(Pile* pP, TypeDonnee elem)
{
Pile q;
q = (TypeCellule*)malloc(sizeof(TypeCellule)); 
q->donnee = elem; 
q->suivant = *pP;
*pP =q; /* mise à jour de la tête de liste */
}
int Depiler(Pile *pP, TypeDonnee *pelem)
{
Pile q;
if(EstPileVide(*pP))
return 1;
*pelem = (*pP)->donnee; 
q = *pP;
*pP = (*pP)->suivant; /* passage au suivant */
free(q); 
 return 0;
}
void DetruirePile(Pile *pP)
{
Pile q;
while(*pP != NULL) 
{
q = *pP;
*pP = (*pP)->suivant;
free(q);
}
*pP = NULL; 
}
/*                       File                       */
File InitialiserFile()
{
File filevide;
filevide.tete=NULL; /* liste vide : NULL */
}
int EstFileVide(File F)
{
return (F.tete == NULL) ? 1 : 0;
}
int EstFilePleine(File F)
{
return 0;
}
int AccederTete(File F, TypeDonnee *pelem)
{
if (EstFileVide(F))
return 1; 
*pelem = F.tete->donnee; 
return 0;
}
void Enfiler(File *pF, TypeDonnee elem)
{
TypeCellule *q;
q = (TypeCellule*)malloc(sizeof(TypeCellule)); /* allocation */
q->donnee = elem;
q->suivant = NULL; /* suivant de la dernière cellule NULL */
if (pF->tete == NULL) /* si file vide */
{
pF->queue = pF->tete = q;
}
else
{
pF->queue->suivant = q; /* insertion en queue de file */
pF->queue = q;
}
}
char Defiler(File *pF, TypeDonnee *pelem)
{
TypeCellule *p;
if (EstFileVide(*pF))
return 1; /* retour d’un code d’erreur */
*pelem = pF->tete->donnee; /* on renvoie l’élément */
p = pF->tete; /* mémorisation de la tête de liste */
pF->tete = pF->tete->suivant; /* passage au suivant */
free(p); 
return 0
}
void DetruireFile(File *pF)
{
TypeCellule *p, *q;
p=pF->tete; 
while (p!= NULL)
{
q = p; /* mémorisation de l’adresse */
p = p->suivant;
free(q);
}
pF->tete = NULL; /* on met la liste à vide */
}