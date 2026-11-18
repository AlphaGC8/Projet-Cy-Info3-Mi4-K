#include <stdio.h>
#include <stdlib.h>
#define MAX_ANNEE 20

#include "../include/year_data.h"

Annee initialiser_tableau(){
	for(int i =0; i<20; i++){
		tab[i].nmbaccident = 0;
		tab[i].indemne = 0;
		tab[i].tue = 0;
		tab[i].blessegrave = 0;
		tab[i].blesseleger = 0;
	}
}

Annee charger_tableau(Annee tab[], FILE *f){
    int tmp2;
	int year;
	int blesse;
	int idmax;
	
	while(fscanf(f, "%d;%d;%d;%d;%d;%d;%d;%d;%d", &year, &idmax, &tmp2, &tmp2, &tmp2, &blesse, &tmp2, &tmp2, &tmp2)==9) {
	
		tab[year-2005].nmbaccident = max(idmax, tab[year-2005].nmbaccident);
		
		if (blesse==1) {
			tab[year-2005].indemne++;
		}
		if (blesse==2) {
			tab[year-2005].tue++;
		}
		if (blesse==3) {
			tab[year-2005].blessegrave++;
		}
		if (blesse==4) {
			tab[year-2005].blesseleger++;
		}
		
    }
    return tab[];
}



int max(int a, int b) {
	if (a>b) return a;
	else return b;
}


int main(int argc, char ** argv){
    FILE * f = fopen(argv[1], "r");
	Annee tab[MAX_ANNEE];

	char tmp[1000];
	fgets(tmp,999, f);
	

    fclose(f);
    return 0;
}
