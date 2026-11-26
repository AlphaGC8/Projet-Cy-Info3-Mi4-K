#include "../include/crash_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AVL* creerAVL(int id){
    AVL* nouv = (AVL*)malloc(sizeof(AVL));
    if (nouv == NULL) exit(EXIT_FAILURE);

    nouv->id_colision = id;
    nouv->eq = 0;
    nouv->fg = NULL;
    nouv->fd = NULL;

    return nouv;
}

AVL* rotationGauche(AVL* a){
    AVL* pivot = a->fd;
    int eq_a = a->eq, eq_p = pivot->eq;

    a->fd = pivot->fg;
    pivot->fg = a;

    a->eq = eq_a - max(eq_p, 0) - 1;
    pivot->eq = min3(eq_a - 2, eq_a + eq_p - 2, eq_p -1);

    return pivot;
}

AVL* rotationDroite(AVL* a){
    AVL* pivot = a->fg;
    int eq_a = a->eq, eq_p = pivot->eq;

    a->fg = pivot->fd;
    pivot->fd = a;

    a->eq = eq_a + min(eq_p, 0)- 1;
    pivot->eq = max3(eq_a + 2, eq_a - eq_p + 2, eq_p + 1);

    return pivot;
}

AVL* doubleGauche(AVL* a){
    a->fd = rotationDroite(a->fd);
    return rotationGauche(a);
}

AVL* doubleDroite(AVL* a){
    a->fg = rotationGauche(a->fg);
    return rotationDroite(a);
}

AVL* equilibrerAVL(AVL* a){
    if(a->eq >= 2){
        if(a->fd->eq >= 0){
            return rotationGauche(a);
        }
        else {
            return doubleGauche(a);
        }
    }

    else if(a <= -2){
        if(a->fg->eq <= 0){
            return rotationDroite(a);
        }
        else {
            return doubleDroite(a);
        }
    }
    return a;
}

AVL* insertionAVL(AVL* a, int e, int *h){
    if(a == NULL){
        *h = 1;
        return creerAVL(e);
    }
    else if (e < a->id_colision){
        a->fg = insertionAVL(a->fg, e, h);
        *h = -*h;
    }
    else if (e > a->id_colision){
        a->fd = insertionAVL(a->fd, e, h);
    }
    else{
        *h = 0;
        return a;
    }
    if(*h != 0){
        a->eq += *h;
        a = equilibrerAVL;
        *h = (a->eq == 0) ? 0 : 1;
    }
}


main(){
    return 0;
}