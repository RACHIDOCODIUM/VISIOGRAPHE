/*Biblio.h-------------------------------*/
#if defined(BIBLIO_H)
#else
#define BIBLIO_H
#define Max 10000
/*-------------------Structure definie pour implementer l'arc------------------ */
struct eltadj
{
    int Dest;                               // Extremite de l'arc
    int Info;                              //les informations par rapport a l'arc
    struct eltadj *suivant;               // un pointeur pour faire les chainage
};
/*-------------Structure pour les sommets----------------------------*/
typedef int TypeDonnee;
struct Sommet
{
    int Indice;
    TypeDonnee InfoSommet;
    struct Sommet *suivant;
    struct eltadj *ListeElAdj;
};
struct graphe{
    int NbSommet;
    int NbArc;
    int MaxS;
    struct Sommet *PremierSommet;
    struct Sommet *DernierSommet;
};
typedef struct newliste{
  TypeDonnee donnee;
  struct newliste *suivant;
}TypeCellule;
typedef struct Sommet TypeSommet;
typedef struct graphe Graphe;
typedef struct eltadj EltAdj;
/*           ------- Ajouter des tetes des primitives Pile, File, Liste pour les manupulatins du Graphes--*/
typedef TypeCellule* Pile;
Pile InitialiserPile();
int EstPileVide(Pile);
int EstPilePleine(Pile);
int AccederSommet(Pile);
void Empiler(Pile*,TypeDonnee);
void Depiler(Pile*,TypeDonnee*);
void DetruirePile(Pile*);
typedef struct 
{
    TypeCellule *tete,*queue;
}File;
File InitialiserFile();
int EstFileVide()

#endif
