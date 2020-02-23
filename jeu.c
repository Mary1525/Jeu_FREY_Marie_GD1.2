#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/////////////////////////////////////////////////////////////////////////////MONSTRE////////////////////////////
struct Monstre
{
    int life;
    int pm;
    int degats;
    int oResistance;
    int resistance;
    int poison;
    int agro;
    int choix;
};

typedef struct Monstre monstre;

struct Perso
{
    int id;
    int life;
    int maxLife;
    int pm;
    int degat;
    int xp;
    int niveau;
    int resistance;
    int choix;
};

typedef struct Perso perso;

struct Lieu{
	char nom[50];
	char description[500];
	int difficult;
	int tID[10];
};

typedef struct Lieu lieu;

/////////////////CREATION MONSTRE///////////
void creationMonstre(monstre tMonstre[], int nbMonstre)
{

    for (int i = 0; i < nbMonstre; i++)
    {

        tMonstre[i].life = 100;

        tMonstre[i].pm = 5;

        tMonstre[i].degats = (rand() % 11) + 10;

        if (tMonstre[i].degats > 15)
        {
            tMonstre[i].oResistance = 1;
        }
        else
        {
            tMonstre[i].oResistance = 2;
        }

        tMonstre[i].resistance = tMonstre[i].oResistance;
        tMonstre[i].poison = 0;
        tMonstre[i].agro = 0;
    }
}

////////////////////////ACTION DES MONSTRES///////////////////////
void actionMonstre(monstre tMonstre[], perso tPerso[], int nbMonstre)
{
    for (int i = 0; i < nbMonstre; i++)
    {
        if (tMonstre[i].life > 0)
        {
            if (tMonstre[i].agro == 1)
            {
                tPerso[2].life -= tMonstre[i].degats / tPerso[2].resistance;
                tMonstre[i].agro = 0;
                printf("Le monstre %d a attaquer le tank car il l'avait agro. Le tank a %d pv.\n", i, tPerso[2].life);
            }
            else
            {
                if (tMonstre[i].pm >= 5 && tMonstre[i].life < 90)
                {
                    //1 pour le soin, 2 pour l'attaque et 3 pour se protéger
                    tMonstre[i].choix = (rand() % 3) + 1; //entre 1 et 3
                }
                else
                {
                    //2 pour l'attaque et 3 pour se protéger
                    tMonstre[i].choix = (rand() % 2) + 2; // entre 2 et 3
                }

                if (tMonstre[i].choix == 1)
                {
                    tMonstre[i].life += 20;
                    if (tMonstre[i].life > 100)
                    {
                        tMonstre[i].life = 100;
                    }

                    tMonstre[i].pm -= 5;
                    printf("Le monstre %d se soigne, il a maintenant %d de points de vie\n", i, tMonstre[i].life);
                }

                if (tMonstre[i].choix == 2)
                {
                    int persoChoisi = (rand() % 3);
                    tPerso[persoChoisi].life -= tMonstre[i].degats / tPerso[persoChoisi].resistance;
                    printf("Le monstre %d attaque le perso %d, il a maintenant %d de points de vie.\n", i, persoChoisi + 1, tPerso[persoChoisi].life);
                }

                if (tMonstre[i].choix == 3)
                {
                    tMonstre[i].resistance *= 2;
                    printf("Le monstre %d resiste ! Les degats qu'il recoit sont divises par %d.\n", i, tMonstre[i].resistance);
                }
            }

        }
    }
}

int checkMonstreChoisi(monstre tMonstre[], int choix, int nbMonstre)
{

    //int tSize = (int)( sizeof(tMonstre) / sizeof(tMonstre[0]));

    if (choix < nbMonstre && choix >= 0 && tMonstre[choix].life > 0)
    {
        return 1;
    }
    return 0;
}


///////////////////////////////////////////////////////////////////////////PERSONNAGE/////////////////////////////////////////////////


////////////////////////////////////GAIN EXPERIENCE/////////////////////////
void xpPerso(perso *perso)
{
    if (perso->xp == perso->niveau)
    {
        perso->maxLife += 10;
        perso->life = perso->maxLife;
        perso->niveau++;
        perso->xp = 0;

        //printf("xp : %d, niveau : %d, maxlife: %d, life : %d\n",perso->xp, perso->niveau, perso->maxLife, perso->life);
    }
}

/////////////////////////////////////ACTION PERSONNAGES/////////////////////////////////////////
// ne reconnait pas perso donc je laisse struct Perso mais reconnait monstre
void actionPerso(perso *perso, monstre tMonstre[], struct Perso tPerso[], int nbMonstre)
{
    int monstreChoisi;
    int check = 0;
    int choix = 0;

    for (int i = 0; i < nbMonstre; i++)
    {
        if (tMonstre[i].life > 0)
        {
            printf("Caracteristiques du monstre %d : %d pv, %d degats, %d resitance\n", i, tMonstre[i].life, tMonstre[i].degats, tMonstre[i].resistance);
        }
    }

    while (check == 0)
    {
        printf("\nTape 1 pour attaquer, 2 pour l'action speciale ou 3 pour te proteger.\n");
        scanf("%d", &perso->choix);

        //Verifie que le joueur ne donne pas un autre chiffre que 1, 2 ou 3
        //Vérifie si le mage et l'archer ont assez de mana pour leurs actions spéciales
        if (perso->choix == 2 && perso->pm >= 5 && perso->id != 3)
        {
            check = 1;
        }
        else if (perso->choix == 2 && perso->pm < 5 && perso->id != 3)
        {
            printf("Vous n'avez plus assez de pm.\n");
        }
        //Vérifie les deux autres actions
        if (perso->choix == 3 || perso->choix == 1 || (perso->choix == 2 && perso->id == 3))
        {
            check = 1;
        }
    }

    if (perso->choix == 1)
    {
        while (choix == 0)
        {
            //printf("1");
            printf("Choisissez un monstre a attaquer.\n");
            scanf("%d", &monstreChoisi);

            choix = checkMonstreChoisi(tMonstre, monstreChoisi, nbMonstre);
        }

        tMonstre[monstreChoisi].life -= perso->degat / tMonstre[monstreChoisi].resistance;
        printf("Le monstre %d a subit %d degats.\n\n", monstreChoisi, perso->degat / tMonstre[monstreChoisi].resistance);

        if (tMonstre[monstreChoisi].life <= 0)
        {
            printf("Le monstre %d est mort.\n\n", monstreChoisi);
            perso->xp++;
            xpPerso(perso);
        }
    }
    if (perso->choix == 3)
    {
        perso->resistance *= 2;
        printf("Vous subissez 2x moins de degats pendant se tour.\n\n");
    }

    if (perso->choix == 2)
    {

        //mage
        //ajouter une protection
        if (perso->id == 1)
        {
            int i;
            printf("Choix du perso a soigner 1 mage, 2 archer ou 3 tank.\n");
            scanf("%d", &i);
            i--;
            tPerso[i].life += 20;
            perso->pm -= 5;
            if (tPerso[i].life > 100)
            {
                tPerso[i].life = 100;
            }
            printf("Vous avez %dPM, le perso %d a %dPV\n\n", perso->pm, i + 1, tPerso[i].life);
        }
        //archer
        if (perso->id == 2)
        {
            while (choix == 0)
            {
                printf("Choisissez un monstre a empoisonner.\n");
                scanf("%d", &monstreChoisi);

                choix = checkMonstreChoisi(tMonstre, monstreChoisi, nbMonstre);
            }
            tMonstre[monstreChoisi].life -= 10;
            tMonstre[monstreChoisi].poison = 2;
            perso->pm -= 5;
            printf("Vous avez %dPM, le monstre %d a %dPV\n\n", perso->pm, monstreChoisi, tMonstre[monstreChoisi].life);
        }

        //tank
        if (perso->id == 3)
        {
            while (choix == 0)
            {
                printf("Choisissez un monstre a agro.\n");
                scanf("%d", &monstreChoisi);

                choix = checkMonstreChoisi(tMonstre, monstreChoisi, nbMonstre);
            }
            tMonstre[monstreChoisi].agro = 1;
            printf("Le tank a agro le monstre %d.\n\n", monstreChoisi);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////LIEUX///////////////////////////////////////////


void deplacements( lieu tLieu[],int destinationChoice, int conditionBooleen, int exitChoice,int comptMonstreMort,int nbMonstre){

	
	while (destinationChoice<=3){	
			
		conditionBooleen==1;
			
		if(destinationChoice==1){
			
			nbMonstre= (rand() % 3) + 1;
			printf ("\n La Ville de %s, %s , cette ville a un niveau de danger de %d/19\n",tLieu[0].nom,tLieu[0].description,tLieu[0].difficult);
			printf ("\n Attention ! %d monstres arrivent vers vous !\n",nbMonstre);
			
			if(comptMonstreMort == nbMonstre){	
				
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
							deplacements(tLieu, destinationChoice,conditionBooleen,exitChoice, comptMonstreMort,nbMonstre);

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
			
		if(destinationChoice==2){
			
			nbMonstre= (rand() % 6) + 3;
			
			printf ("\n La Ville de %s, %s , cette ville a un niveau de danger de %d/19\n",tLieu[1].nom,tLieu[1].description,tLieu[1].difficult);
			printf ("\n Attention ! %d monstres arrivent vers vous !\n",nbMonstre);
			
			if(comptMonstreMort == nbMonstre){
				printf("moooort");
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
							deplacements(tLieu, destinationChoice,conditionBooleen,exitChoice, comptMonstreMort,nbMonstre);

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
			
			
		if(destinationChoice==3){
			
			nbMonstre= (rand() % 10) + 6;
			
			printf ("\n La Ville de %s, %s , cette ville a un niveau de danger de %d/19\n",tLieu[2].nom,tLieu[2].description,tLieu[2].difficult);
			printf ("\n Attention ! %d monstres arrivent vers vous !\n",nbMonstre);
			
			if(comptMonstreMort == nbMonstre){
			
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
							deplacements(tLieu, destinationChoice,conditionBooleen,exitChoice, comptMonstreMort,nbMonstre);

							
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
			deplacements(tLieu, destinationChoice,conditionBooleen,exitChoice, comptMonstreMort,nbMonstre);
		}
		
		else if (exitChoice==1){
				
			conditionBooleen==0;
			printf("Adieu brave aventurier");
		}
		
		}
	}
};

int main()
{
	int destinationChoice;
	int conditionBooleen;
	int exitChoice;
	
    int persoChoisi;
    int nbMonstre;
    int comptMonstreMort = 0;

    srand(time(NULL));

    //Creation Perso

    perso mage = {1, 100, 100, 20, 2, 0, 1, 1};
    perso archer = {2, 100, 100, 5, 20, 0, 1, 1};
    perso tank = {3, 100, 100, 0, 15, 0, 1, 2};

    perso tPerso[3] = {mage, archer, tank};
	
	//Creation lieux
	
	lieu lieu0 = {"Somali","Cette ville connait la famine, des ordes de parasites ont colonises les lieux ",6,1};
	lieu lieu1 = {"Hyrule","Il y a des colonies de gobelins qui peuplent la ville",12,{0,2}};
	lieu lieu2 = {"Wuhan","Dans cette ville un virus mortel est vehicule dans l'air",19,1};

	lieu tLieu[10] = {lieu0,lieu1,lieu2};
	
	//choix du personnage
	printf("Quel personnage voulez vous choisir ? \n");
	printf("\nSi vous jouez le mage(1) voici ses statistiques :\nPV : %d\nPM : %d\nDegats :%d\nResistance :%d\nAction speciale : soin\n\n", tPerso[0].life, tPerso[0].pm, tPerso[0].degat, tPerso[0].resistance);
	printf("\nSi vous jouez l'archer(2) voici ses statistiques :\nPV : %d\nPM : %d\nDegats :%d\nResistance :%d\nAction speciale : fleche empoisonnes\n\n", tPerso[1].life, tPerso[1].pm, tPerso[1].degat, tPerso[1].resistance);
	printf("\nSi vous jouez le tank(3) voici ses statistiques :\nPV : %d\nPM : %d\nDegats :%d\nResistance :%d\nAction speciale : agro\n\n", tPerso[2].life, tPerso[2].pm, tPerso[2].degat, tPerso[2].resistance);
	printf("saisissez le numero correspondant");
	scanf ("%d",& persoChoisi);
	
	
	
	// choix du lieux
	printf ("\nQuelle destination veux tu choisir ?\n");
	printf ("1)%s (jusqu'a 3 monstres) 2)%s (jusqu'a 6 monstres)  3)%s (jusqu'a 10 monstres) \n",tLieu[0].nom,tLieu[1].nom,tLieu[2].nom);
		
	scanf("%d",&destinationChoice);
	
	deplacements(tLieu, destinationChoice,conditionBooleen,exitChoice, comptMonstreMort,nbMonstre);
	

	
    monstre tMonstre[nbMonstre];
    creationMonstre(tMonstre, nbMonstre);
	
	//tour de jeu
	actionPerso(&tPerso[persoChoisi], tMonstre, tPerso, nbMonstre);

    while (tPerso[persoChoisi].life > 0 && comptMonstreMort < nbMonstre)
    {
        printf("\nNouveau tour\n");
        // avant que le joueur ne joue
        // regain d'un point de mana
        if (tPerso[0].pm < 20)
        {
            tPerso[0].pm++;
        }
        if (tPerso[1].pm < 5)
        {
            tPerso[1].pm++;
        }

        // pour les monstres
        for (int i = 0; i < nbMonstre; i++)
        {

            // regain de mana
            if (tMonstre[i].pm < 5)
            {
                tMonstre[i].pm++;
            }
            // action du poison si necessaire
            if (tMonstre[i].poison > 0)
            {
                tMonstre[i].poison--;
                tMonstre[i].life -= 10;
                printf("\nLe monstre %d a perdu 10 PV avec le poison.\n", i);
            }
        }
		

		//avant le tour des monstres
        for (int i = 0; i < nbMonstre; i++)
        {
            tMonstre[i].resistance = tMonstre[i].oResistance;
        }
		
		//tour des monstres
        actionMonstre(tMonstre, tPerso, nbMonstre);
		
		//Une fois le tour terminer
        tPerso[0].resistance = 1;
        tPerso[1].resistance = 1;
        tPerso[2].resistance = 2;

        //compte le nombre de monstres morts
        comptMonstreMort = 0;
        for (int i = 0; i < nbMonstre; i++)
        {
            if (tMonstre[i].life <= 0)
            {
                comptMonstreMort++;
            }
        }
        printf("\nVous avez tue %d monstres au total.\n", comptMonstreMort);
    }
	


    return 0;
}
