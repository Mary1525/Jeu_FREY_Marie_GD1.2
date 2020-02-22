#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Lieu{
	char nom[50];
	char description[500];
	int difficult;
	int tID[10];
};

typedef struct Lieu lieu;

void deplacements( lieu tLieu[],int destinationChoice, int conditionBooleen, int exitChoice){

	
	while (destinationChoice<=3){	
			
		conditionBooleen==1;
			
		if(destinationChoice==1){
				
			printf ("\n La Ville de %s, %s , cette ville a un niveau de danger de %d/19\n",tLieu[0].nom,tLieu[0].description,tLieu[0].difficult);
			printf ("\nQuelle destination veux tu choisir ?\n");
			printf ("1)%s  2)%s  3)%s \n",tLieu[0].nom,tLieu[1].nom,tLieu[2].nom);
			scanf("%d",&destinationChoice);
			
				
			if( destinationChoice==2){
				printf("Destination eligible !");
				printf ("\n La Ville de %s, %s , cette ville a un niveau de danger de %d/19\n",tLieu[1].nom,tLieu[1].description,tLieu[1].difficult);
				scanf("%d",&destinationChoice);
			
			}
				
			else {
					
					
				if(destinationChoice>=3){
			
					printf("Choisis un chiffre entre 1 et 3 STP !!!\n");
					printf("Veux tu quitter le jeux ?\n");
					printf("1) OUI ou 2) NON \n");
					scanf( "%d",& exitChoice);
			
					if (exitChoice==2){
								
						conditionBooleen==1;
						printf("recommencons!");
						printf ("\nQuelle destination veux tu choisir ?\n");
						printf ("1)%s  2)%s  3)%s \n",tLieu[0].nom,tLieu[1].nom,tLieu[2].nom);
					
						scanf("%d",&destinationChoice);
						conditionBooleen==1;
					}
					
					else if (exitChoice==1){
								
						conditionBooleen==0;
						printf("Adieu brave aventurier");
					}
					
				}
					
				printf ("Tu es trop loin de cette destination ! Choisis-en une autre !");
				printf ("\nQuelle destination veux tu choisir ?\n");
				printf ("1)%s  2)%s  3)%s \n",tLieu[0].nom,tLieu[1].nom,tLieu[2].nom);
				scanf("%d",&destinationChoice);
			}
		}
			
		if(destinationChoice==2){
				
			printf ("\n La Ville de %s, %s , cette ville a un niveau de danger de %d/19\n",tLieu[1].nom,tLieu[1].description,tLieu[1].difficult);
			printf ("\nQuelle destination veux tu choisir ?\n");
			printf ("1)%s  2)%s  3)%s \n",tLieu[0].nom,tLieu[1].nom,tLieu[2].nom);
			scanf("%d",&destinationChoice);
			
			
			if( destinationChoice==1){
				printf("Destination eligible !");
				printf ("\n La Ville de %s, %s , cette ville a un niveau de danger de %d/19\n",tLieu[0].nom,tLieu[0].description,tLieu[0].difficult);
				scanf("%d",&destinationChoice);
					
			}
				
			else if( destinationChoice==3){
					
				printf("Destination eligible !");
				printf ("\n La Ville de %s, %s , cette ville a un niveau de danger de %d/19\n",tLieu[2].nom,tLieu[2].description,tLieu[2].difficult);
				scanf("%d",&destinationChoice);
					
			}
				
			else {
				
				if(destinationChoice>=3){
			
					printf("Choisis un chiffre entre 1 et 3 STP !!!\n");
					printf("Veux tu quitter le jeux ?\n");
					printf("1) OUI ou 2) NON \n");
					scanf( "%d",& exitChoice);
			
					if (exitChoice==2){
								
						conditionBooleen==1;
						printf("recommencons!");
						printf ("\nQuelle destination veux tu choisir ?\n");
						printf ("1)%s  2)%s  3)%s \n",tLieu[0].nom,tLieu[1].nom,tLieu[2].nom);
		
						scanf("%d",&destinationChoice);
						conditionBooleen==1;
					}
					
					else if (exitChoice==1){
								
								conditionBooleen==0;
								printf("Adieu brave aventurier");
					}
					
				}
					
				printf ("Tu es trop loin de cette destination ! Choisis-en une autre !");
				printf ("\nQuelle destination veux tu choisir ?\n");
				printf ("1)%s  2)%s  3)%s \n",tLieu[0].nom,tLieu[1].nom,tLieu[2].nom);
				scanf("%d",&destinationChoice);
					
			}
		}	
			
			
		if(destinationChoice==3){
			
			printf ("\n La Ville de %s, %s , cette ville a un niveau de danger de %d/19\n",tLieu[2].nom,tLieu[2].description,tLieu[2].difficult);
			printf ("\nQuelle destination veux tu choisir ?\n");
			printf ("1)%s  2)%s  3)%s \n",tLieu[0].nom,tLieu[1].nom,tLieu[2].nom);
			scanf("%d",&destinationChoice);
			
			
			if( destinationChoice==2){
				printf("Destination eligible !");
				printf ("\n La Ville de %s, %s , cette ville a un niveau de danger de %d/19\n",tLieu[1].nom,tLieu[1].description,tLieu[1].difficult);
				scanf("%d",&destinationChoice);
					
			}
			
			else {

					
				if(destinationChoice>=3){
			
					printf("Choisis un chiffre entre 1 et 3 STP !!!\n");
					printf("Veux tu quitter le jeux ?\n");
					printf("1) OUI ou 2) NON \n");
					scanf( "%d",& exitChoice);
			
					if (exitChoice==2){
								
						conditionBooleen==1;
						printf("recommencons!");
						printf ("\nQuelle destination veux tu choisir ?\n");
						printf ("1)%s  2)%s  3)%s \n",tLieu[0].nom,tLieu[1].nom,tLieu[2].nom);
						scanf("%d",&destinationChoice);
						conditionBooleen==1;
						
					}
					
					else if (exitChoice==1){
								
						conditionBooleen==0;
						printf("Adieu brave aventurier");
					}
		
				}
				
				printf ("Tu es trop loin de cette destination ! Choisis-en une autre !");
				printf ("\nQuelle destination veux tu choisir ?\n");
				printf ("1)%s  2)%s  3)%s \n",tLieu[0].nom,tLieu[1].nom,tLieu[2].nom);
				scanf("%d",&destinationChoice);
		
			}
		}	
	}	
	
	if(destinationChoice>=3){
			
		printf("Choisis un chiffre entre 1 et 3 STP !!!\n");
		printf("Veux tu quitter le jeux ?\n");
		printf("1) OUI ou 2) NON \n");
		scanf( "%d",& exitChoice);
			
		if (exitChoice==2){
				
			conditionBooleen==1;
			printf("recommencons!");
			printf ("\nQuelle destination veux tu choisir ?\n");
			printf ("1)%s  2)%s  3)%s \n",tLieu[0].nom,tLieu[1].nom,tLieu[2].nom);
			scanf("%d",&destinationChoice);
			conditionBooleen==1;
		}
		
		else if (exitChoice==1){
				
			conditionBooleen==0;
			printf("Adieu brave aventurier");
		}
		
	}
};


int main(){
	
	int destinationChoice;
	int conditionBooleen;
	int exitChoice;
	
	
	lieu lieu0 = {"Somali","Cette ville connait la famine ",6,1};
	lieu lieu1 = {"Hyrule","Il y a des colonies de gobelins qui peuplent la ville",12,{0,2}};
	lieu lieu2 = {"Wuhan","Dans cette ville un virus mortel est vehicule dans l'air",19,1};

	lieu tLieu[10] = {lieu0,lieu1,lieu2};
		
	printf ("\nQuelle destination veux tu choisir ?\n");
	printf ("1)%s  2)%s  3)%s \n",tLieu[0].nom,tLieu[1].nom,tLieu[2].nom);
		
	scanf("%d",&destinationChoice);
	
	deplacements(tLieu, destinationChoice,conditionBooleen, exitChoice);
		
	while (conditionBooleen==1){
			
		deplacements(tLieu, destinationChoice,conditionBooleen, exitChoice);
	}
	
	
return 0;

}
	
	
	
