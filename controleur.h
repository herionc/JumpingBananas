/********************************************************************************************************************************************************************************
*			Header File reprenant les "include", variables et prototypes permettant de "controler" les personnages tels que: singe, ennemis, armes(boules) et fruits)			*
*			Projet: Jumping Bananas "modifié" dans le cadre de ma première année en Bachelier en sciences informatiques de l'université de Namur								*
*			Auteur: Christophe Hérion																																			*
*************1******************************************************************************************************************************************************************/

#ifndef CONTROLEUR_H
#define CONTROLEUR_H
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "textures.h"



/************************
*	Enumeration:		*
************************/
typedef enum direction Direction;					// permet de faciliter le codage de certaines fonctions telles que: déplacements etc...
enum direction{
	GAUCHE, DROITE
};


/************************************************************************************
*  Structure des personnages (pincipal, ennemis, armes et probablement récompenses)	*
************************************************************************************/

typedef struct personnages Personnages;
struct personnages{

	int nbVie;										// nombre de vie du personnage
	int posX; 										// Coordonnée X 
	int posY;										// Coordonnée Y
	GLuint texture;									// Permet de "coller" une texture sur le personnage
	Direction direction;							// Permet de connaitre la direction du personnage
};


// Structure du jeu (doit encore évoluer pour comprendre les structures des ennemis, des armes, récompenses, état du jeu etc...)
typedef struct jumpingB JumpingB;
struct jumpingB{

	Personnages singe;								// Strucure représentant le personnage principal
	};




JumpingB jeu; 										// Déclaration du jeu jumpingBananas


/****************************
*  Prototypes de fonctions	*
****************************/
void initJumpingB();								// Initialisation du jeu
void initSinge(Personnages *singe);					// Initialisation du personnage principal
void keyboard(unsigned char key, int x, int y);		// Configuration des touches (juste esc et f pour le moment)	

void initOpenGL();

void reshape(int width, int height);				// redimensionnement de la fenetre à chaque passage de boucle glut


#endif