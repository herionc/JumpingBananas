/****************************************************************************************************************************************************************
*		Header File reprenant les "include", variables et prototypes en rapport avec la récupération du contenu du fichier map.txt qui sert à stocker la map	*
*		Projet: Jumping Bananas modifié dans le cadre de ma première année en Bachelier en sciences informatiques à l'université de Namur						*
*		Auteur: Christophe Hérion																																*
*********1******************************************************************************************************************************************************/

#ifndef MAP_H
#define MAP_H
#include <GL/glut.h>


/***************
*  Defines:	   *
***************/ 
#define MAX 256
#define TAILLE 25

/***************
*  Variables:  *
***************/
char map [TAILLE][TAILLE];							// Tableau map[][] qui permet de stocker le contenu du fichier map.txt									


/*****************************
*  Prototypes de fonctions:  *
*****************************/
void lireMap (char map[TAILLE][TAILLE]);			// Lit le fichier map.txt et place le contenu dans le tableau map[TAILLE][TAILLE]

#endif