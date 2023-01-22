/*Biblio.h-------------------------------*/
#if defined(BIBLIO_H)
#else
#define BIBLIO_H
#define Max 10000
/*-------------------Structure definie pour implementer l'arc------------------ */
typedef struct EltAdj
{
    int Dest;                               // Extremite de l'arc
    int Info;                              //les informations par rapport a l'arc
    struct EltAdj *suivant;               // un pointeur pour faire les chainage
}EltAdj;
/*-------------Structure pour les sommets----------------------------*/
typedef int TypeDonnee;
typedef struct Sommet
{
    int Indice;
    TypeDonnee InfoSommet;
    struct Sommet *suivant;
    struct EltAdj *ListeElAdj;
}TypeSommet;
typedef struct Graphe{
    int NbSommet;
    int NbArc;
    int Max;
    struct TypeSommet *PremierSommet;
    struct TypeSommet *DernierSommet;
}Graphe;
typedef struct newliste{
  TypeDonnee donnee;
  struct newliste *suivant;
}TypeCellule;
#endif
