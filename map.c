#include <stdio.h> 
#include <stdlib.h>
#include "map.h"
#include "textures.h"

/************************************************************************
* Nom: lireMap															*
* Description: 	Extrait la map à partir du fichier map.c 		 		*
* IN: tableau de char de taille 25 afin d'avoir un tableau carré		*
* OUT: void 															* 
* **********************************************************************/
void lireMap (char map[TAILLE][TAILLE]){

	FILE * f = NULL;
	f = fopen ("map.txt", "r");									// assignation de cMap.txt au pointeur "f"
	char ligne[MAX];											// tableau de char (string) permettant de récupérer le resultat retourné par la fonction fgets
	
	int i;
	int j;

	if (f == NULL){												// si f est NULL, alors fopen n'a pas pu ouvrir le fichier --> affichage d'un message d'erreur 
		printf("File could not be opened !\n");
	}
	else{														// sinon, parcours du tableau + récupération du contenu du fichier que l'on assigne au tableau map[][] 
		for (i = 0; i < TAILLE; i++){
			fgets (ligne, MAX, f);
			j = 0;
			do{
				map[i][j] = ligne[j];
				j++;
			}while (j < TAILLE && ligne[j] != '\n');
					
		}
		fclose(f);												// Fermeture du fichier map.txt
	}

}










