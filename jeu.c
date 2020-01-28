#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a = 1;
int b = 3;

int rand_a_b(){
	srand(time(NULL));
	return rand()%(b-a) + a;
}

int main () {

	int pvChacalmalin = 100; //Ennemie
	int pvChienloup = 350; //Hero

	int pMagieChienloup = 5; // Point de magie du héro

	int tour=1;

	int choixanime;
	int choixm = rand_a_b(1,3);

	while (pvChacalmalin >= 0) {
	    int degat = 12;
	    int degatChacal = 24;
	    int degatMagiePoison = 5;
		printf("Vie Chienloup: %d \n", pvChienloup);
		printf("Vie Chacalmalin: %d \n", pvChacalmalin);
		printf("Point de Magie Chienloup: %d \n \n", pMagieChienloup);
		
		printf("Voulez vous attaquer (1), vous defendre (2) ou envoyer un sort de poison (3):\n");
		scanf("%d", &choixanime); // Quand le joueur prend un choix
		printf("\n");

		
		switch(choixanime)
			{
		
			case 1 : // Si j'attaque alors
				switch(choixm) // Le monstre choisit
				{ 
				case 1 :
					printf("Vous attaquez le Chacal malin \n \n");
					pvChacalmalin = pvChacalmalin - degat;
					printf("Le Chacal a subit %d degats \n \n", degat);
					printf("Les points de vie de Chacal Malin sont de: %d \n \n", pvChacalmalin);
				break;
				
				case 2 :
					printf("Vous attaquez le Chacal malin \n \n");
					pvChacalmalin = pvChacalmalin - degat/2;
					printf("Chacalmalin se défend!\n");
				break;
				
				}
			break;
				
			case 2 : // Si je me défend alors 
			
				switch(choixm)
				{
				case 1 :
					printf("Vous vous défendez!\n");
					degatChacal = degatChacal/4;
					pvChienloup = pvChienloup - degatChacal;
					printf("Vous subissez %d degats \n", degatChacal);
				break;
				
				case 2 :
					printf("Vous vous défendez!\n");
					printf("Chacalmalin se défend!\n");
				
				break;
				}

			case 3 :// Si j'empoisone l'adversaire alors

				switch(choixm)
				{ 
				case 1 : // Le chacal subit le degat de poison
					printf("Vous empoisonnez le Chacal malin. \n \n");
					pvChacalmalin = pvChacalmalin - degatMagiePoison;
					printf("Vous dépensez 3 points de magie. \n \n");
					pMagieChienloup = pMagieChienloup - 3;
					printf("Le poison provoque au Chacal %d degats \n \n", degatMagiePoison);
					printf("Les points de vie de Chacal Malin sont de: %d \n \n", pvChacalmalin);
				break;
				
				case 2 : // Je ne peux pas jeter un sort
				     (pMagieChienloup <= 2);
                     printf("Impossible d'envoyer de sort poison. \n");
	                 printf("Choisissez une autre action. \n");
		        break;
				    
				}
			break;

		}
		

		printf("_______________________ %d \n \n", tour);
		tour = tour + 1;

        printf("Vous récupérez 1 point de magie. \n");
		pMagieChienloup = pMagieChienloup + 1;
		
		
		if (pvChacalmalin <= 0)
		{
			printf("Le chacal a été abbatue.");
			break;
		}
		if (pvChienloup <= 0)
		{
			printf("Wasted");
			break;
		}
	}

	return 0;
}
