#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Graphe.h"
int Initialiser(Graphe *G)
{
    G->NbSommet=0;
    G->NbArc=0;
    G->MaxS=0;
    G->PremierSommet=NULL;
    G->DernierSommet=NULL;
}
int AjouterSommet(Graphe *G,int Info)
{
    TypeSommet *pointeur;
    G->MaxS++;
    pointeur=(TypeSommet*)malloc(sizeof(TypeSommet));
    if(pointeur==NULL)
    {
        printf("\n\tERREUR ! Memoire est insuffisante pour creer un sommet.");
        return -1;
    }
    else
    {
        pointeur->Indice=G->MaxS;
        pointeur->InfoSommet=Info;
        pointeur->suivant=NULL;
        pointeur->ListeElAdj=NULL;
        if(G->NbSommet==0)
        {
            G->PremierSommet=pointeur;
            G->DernierSommet=pointeur;
        }else
        {
            G->PremierSommet->suivant=pointeur;
            G->DernierSommet=pointeur;
        }
        G->NbSommet++;
        return pointeur->Indice;
    }
}
int AjouterArc(Graphe *G,int a,int b,int Info)
{
 TypeSommet *psommet1,*psommet2;
 EltAdj *padj,*precedent;
 psommet1=G->PremierSommet;
 /* On parcour les sommets jusqu'a trouver a */
 while(psommet1!=NULL)
 {
     if(psommet1->Indice==a)break;
     psommet1=psommet1->suivant;
 }
 if(psommet1==NULL)
 {
     printf("\n\tErreur ! Creation d'un arc dont l'origine n'existe pas");
     return -1;
 }
 else /* on a trouve */
 {
    padj=psommet1->ListeElAdj;
    /*on parcourt les sommets pour trouver les b */
   psommet2=G->PremierSommet;
   while(psommet2!=NULL)
   {
       if(psommet2->Indice==b)break ;
       psommet2=psommet2->suivant;
   }
   if(psommet2==NULL)
   {
       printf("\n\tErreur ! Creation d'un arc dont l'exite pas");
       return -2;
   }
   else /* on a trouver a et b    */
   {
       if(padj==NULL)/* La liste est vide */
       {
           padj=(EltAdj*)malloc(sizeof(EltAdj));
           if(padj==NULL)
           {
               printf("\n\tErreur! Memoire insuffisante pour creer un sommet");
               return -3;
           }else
           {
               padj->suivant=psommet1->ListeElAdj;
               psommet1->ListeElAdj=padj;
           }
       }
       else
       {
           while(padj!=NULL)
           {
            if(padj->Dest==b){padj->Info=Info; break;} /* L'arc existe, upadate info*/
            if(padj->Dest>b){padj=NULL; break;} /* On depasse b sans le trouver*/
            precedent=padj;
            padj=padj->suivant;
           }
           if(padj==NULL) /* L'arc n'exite pas, il faut le creer*/
           {
               padj=(EltAdj*)malloc(sizeof(EltAdj));
               if(padj==NULL)
               {
                   printf("\n\tERREUR! Memoire insuffisante pour creer un sommet");
                   return -3;
               }
               else
               {
                   if(precedent->suivant==NULL)/* element ajouter a la fin */
                   {
                       precedent->suivant=padj;
                       padj->suivant=padj;
                   }
               }
           }
       }
       padj->Dest=b;
       padj->Info=Info;
       G->NbArc++;
   }
   return 0;
 }
}