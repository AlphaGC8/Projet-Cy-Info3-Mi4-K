#include <stdio.h>
#include <stdlib.h>

typedef struct avl{
    int id_colision;
    int eq;
    struct avl *fg;
    struct avl *fd;
}AVL;


AVL* creerAVL(int id);

AVL*rotationDroite(AVL* a);
AVL* rotationGauche(AVL* a);

AVL* doubleDroite(AVL* a);
AVL* doubleGauche(AVL* a);

AVL* equilibrerAVL(AVL* a);
AVL* insertionAVL(AVL* a,int id, int *h);