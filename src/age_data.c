#include "../include/age_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "age_data.h"

typedef struct Chainon{
        int age;
        int nb[2][3];
        struct Chainon* suivant;
} Chainon;

typedef Chainon* PChainon;    

PChainon creerChainon(int age){
     PChainon p = malloc(sizeof(Chainon));
     
     if(p==NULL){
        exit(1);
     }
     p->age = age;
     p->suivant = NULL;
     
     for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
             p->nb[i][j]=0;
         }
     }
     
     return p;
}                
     
     
       
if(genre != 1 && genre !=2){
      continue;
}

if(type < 1 || type > 3){
      continue;
}

if(naissance <= 0 || naissance > annee){
      continue;
}

age= annee - naissance;                      




main(){
    return 0;
}
