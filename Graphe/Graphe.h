#if defined(GRAPHE_H)
#else 
#define GRAPHE_H
#include"../BIBLIOSTRUCT/Biblio.h"
void InitialiserGraphe(Graphe*);
int AjouterSommet(Graphe*,int);
int AjouterArc(Graphe*,int,int,int);
int SupprimerSommet(Graphe*,int);
int SupprimerArc(Graphe*,int,int);
void SupprimerGraphe(Graphe*);
int LireFicher(char*,Graphe*); 
#endif
