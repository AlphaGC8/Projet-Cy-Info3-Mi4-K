#include "../include/year_data.h"

void initialiser_tableau(Annee tab[]){
	for(int i =0; i<20; i++){
		tab[i].nmbaccident = 0;
		tab[i].indemne = 0;
		tab[i].tue = 0;
		tab[i].blessegrave = 0;
		tab[i].blesseleger = 0;
	}
}


void charger_tableau(Annee tab[], FILE *f){
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
}
// pour chaque annee, remplie la structure de l'annee avec les infos dont on a besoin


int max(int a, int b) {
	if (a>b) return a;
	else return b;
}


int actionMenu(Annee tab[]) {
	char rsp[100];
	int year;
	do {
		printf("Voulez-vous connaitre les statistiques d'une annee ? (o pour oui, n pour non)\n");
		if ((scanf(" %s", rsp)!=1) || (strlen(rsp)!=1) || ((rsp[0] != 'o' && rsp[0] != 'n'))) {
				printf("erreur, veuillez reessayer\n");
		}
	} while ((strlen(rsp)!=1) || (rsp[0] != 'o' && rsp[0] != 'n'));
	
	// verifie si le scanf renvoie bien 1 element de 1 caractere, o ou n

	if (rsp[0]=='o') {
		do {
			printf("De quelle annee souhaitez-vous avoir les statistiques ? (entre 2005 et 2024)\n");
			if ((scanf(" %d", &year)!=1) || year>2024 || year<2005) {
				printf("erreur, veuillez reessayer\n");
			}
		} while (year>2024 || year<2005);
		afficherTableau(year, tab);
		return 1;
	}
	
	// si o verifie que l'annee saisi est bien entre 2005 et 2024 et affiche les infos

	else {
		return 0;
	}
}


void menu(Annee tab[]) {
	int n=0;
	do {
		n = actionMenu(tab);
	} while(n!=0);
}
// appelle les actions du menu jusqu'a ce que la personne ne veuille plus d'infos


void afficherTableau(int year, Annee tab[]) {
	printf("En %d, il y a eu : \n %d accident\n %d personnes indemnes lors d'un accident\n %d personnes tuees\n %d personnes blessees gravement\n %d personnes blesses legerement\n", year, tab[year-2005].nmbaccident, tab[year-2005].indemne, tab[year-2005].tue, tab[year-2005].blessegrave, tab[year-2005].blesseleger);
}





int main(int argc, char ** argv){
    FILE * f = fopen(argv[1], "r");
	if (argc < 2) {
    	printf("Erreur, passez le fichier en argument.");
    return 0;
	}

	// verifie qu'il y ait bien 1 element en plus quand on execute (à modifier quand on aura fait plusieurs traitements (passer de 2 à 3))

	if (f == NULL) {
    	printf("erreur, pas de fichier trouvé");
    	return 0;
	}

	Annee tab[MAX_ANNEE];
	initialiser_tableau(tab);

	char tmp[1000];
	fgets(tmp,999, f);
	
	charger_tableau(tab, f);
	menu(tab);

    fclose(f);
    return 0;
}
