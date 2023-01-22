#if _GRAPHE_H_
#define _GRAPHE_H_
typedef struct Cell{
    int nbsommet;
    int **Matrice;
}Graphe;
typedef struct cellsommet{
    int num_som;
    struct cellsucc *Succ;
    struct cellsommet *suivant;
}TypeSommet;
typedef struct cellsucc{
    int num_succ;
    struct cellsommet *extremite;
    struct cellsucc *suivant;
}TypeSucc;
typedef int TypeDonnee;
typedef struct newliste{
  TypeDonnee donnee;
  struct newliste;
}TypeCellule;
#endif
