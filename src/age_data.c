#include "../include/age_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/age_data.h"
   

PChainon creerChainon(int age){
     Chainon* nouv = malloc(sizeof(Chainon));
     
     if(nouv==NULL){
        exit(1);
     }
     nouv->age = age;
     nouv->suivant = NULL;
     
     for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
             nouv->nb[i][j]=0;
         }
     }
     
     return nouv;
}              

PChainon chargerChainon(PChainon tete, FILE * f){
      int annee;
      int role;
      int genre;
      int naissance;
      int tmp2;
      int* n;

      while(fscanf(f, "%d;%d;%d;%d;%d;%d;%d;%d;%d", &annee, &tmp2, &tmp2, &tmp2, &role, &tmp2, &genre, &naissance, &tmp2)==9){
            if((genre == 1 || genre == 2) && (role >=1 && role <= 3) && (naissance > 0 && naissance <= annee)){
                  int age = annee - naissance;
                  PChainon p = rechercherChainon(tete, age, n);

                        if(n == 0){
                              PChainon nouv = creerChainon(age);
                              if(p == NULL){
                                    nouv->suivant = tete;
                                    tete = nouv;
                              }
                              else{
                                    nouv->suivant = p->suivant;
                                    p->suivant = nouv;
                              }
                              p = nouv;
                        }
                        p->nb[genre - 1][role - 1]++;
            }
      }
      return tete;
}

PChainon rechercherChainon(PChainon tete, int age, int* n){
      PChainon p = tete;
      *n = 0;

      if(tete == NULL || age < tete->age) return NULL;

      while(p != NULL){           
            if(p->age == age){
                  *n = 1;
                  return p;
            }

            if(p->suivant == NULL || p->suivant->age > age){
                  return p;
            }

            p = p->suivant;
      }
      return NULL;
}

float pourcentage(){

}

void afficherChainon(PChainon tete,int flitre1, int filtre2){
      
      printf("Pour %d an(s) :\n");
      printf(" - ");
      
}

//Repris du projet de Preing1
// --- LECTURE D'UNE TOUCHE AU MENU ---
// Utilise fgets (pas _getch) car ici on veut que l'utilisateur voie ce qu'il tape
static char lire_touche(void) {
    char buf[8];
    printf("\nEntrez votre choix : ");
    if (fgets(buf, sizeof(buf), stdin) == NULL) return '0';
    return buf[0];   // on ne garde que le premier caractère saisi
}


main(int argc, char ** argv){
      FILE * f = fopen(argv[1], "r");
    return 0;
}