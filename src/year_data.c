#include <stdio.h>
#include <stdlib.h>

typedef struct annee{
	int nmbaccident;
	int indemne;
	int tue;
	int blessegrave;
	int blesseleger;
} Annee;

int max(int a, int b) {
	if (a>b) {
		return a;
	}
	else {
		return b;
	}
}


int main() {
	Annee tab[20];
	for(int i =0, i<20, i++) {
		tab[i].nmbaccident = 0;
		tab[i].indemne = 0;
		tab[i].tue = 0;
		tab[i].blessegrave = 0;
		tab[i].blesseleger = 0;
	}
	
	char tmp[1000];
	fgets(tmp,999, f);
	
	int tmp2 = 0;
	int year = 0;
	int blesse = 0;
	int idmax = 0;
	
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
		
	return 0;
}
