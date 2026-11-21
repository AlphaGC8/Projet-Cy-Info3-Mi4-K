#ifndef YEAR_DATA_H
#define YEAR_DATA_H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ANNEE 20

typedef struct annee{
	int nmbaccident;
	int indemne;
	int tue;
	int blessegrave;
	int blesseleger;
} Annee;

int max(int a, int b);
void initialiser_tableau(Annee tab[]);
void charger_tableau(Annee tab[], FILE *f);
int actionMenu(Annee tab[]);
void menu(Annee tab[]);
void afficherTableau(int year, Annee tab[]);

#endif