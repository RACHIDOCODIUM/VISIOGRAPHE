#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Biblio.h>
Pile InitialiserFile()
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