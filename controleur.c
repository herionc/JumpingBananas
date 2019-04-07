#include "controleur.h"



/****************************************************************************
* Nom: initSinge															*
* Description: Initialise les variables du personnage principal				*
* IN: Pointeur vers la structure Personnages								*
* OUT: void 																* 
* **************************************************************************/
void initSinge(Personnages *singe){

	singe->nbVie = 3;
	singe->posX  = 60;
	singe->posY  = 5;
	singe->direction = DROITE;
	
}


/****************************************************************************
* Nom: initJumpingB															*
* Description: 	Initialise les différentes variables et structures du jeu	*
* IN: void																	*
* OUT: void 																* 
* **************************************************************************/
void initJumpingB(){

	initSinge(&(jeu.singe));
}


/****************************************************************************
* Nom: keyboard																*
* Description: 	configure les différentes touches "normales du clavier"		*
* IN: unsigned char (correspond à la touche utilisée ou à sa valeur ASCII)  *
*	  int x et int y (position en pixels permettant l'utilisation de 		*
*	  la souris)															*
* OUT: void 																* 
* **************************************************************************/
void keyboard(unsigned char key, int x, int y){

	if(key == 27)																// si touche esc: on sort du jeu
		exit(0);
	else if(key == 'f')
		glutFullScreen();														// si touche 'f': on passe en plein ecran
}


/****************************************************************************
* Nom: initOpenGL															*
* Description: 	Initialise certains parametres d'OpenGL tels que:			*
*				la couleur de fond de la fenetre, le choix de la matrice	*
*				et utilise les fonctions d'affichage propre au jeu			*
* IN: void																	*
* OUT: void 																* 
* **************************************************************************/
void initOpenGL(){
	glClearColor ( 42.0f/255 , 48.0f/255 , 48.0f/255 , 1.0);					// Appel "glClearColor" dont les paramètres correspondent aux valeurs RGBA qui seront appliquées 
    glMatrixMode(GL_PROJECTION); 												// Choisit la matrice de projection pour la pile courante
	glLoadIdentity();															// Repasse par la matrice identité
	
	initJumpingB();																// Appel à initJumpingB qui initialise le jeu
	lireMap(map);																// Appel à lire_map() qui lit le fichier map.txt
	initTextures();																// Appel à init_Textures() qui charge toutes les textures du jeu
	
	gluOrtho2D(0, 625, 650, 0);													// Fixe ce que l'on à dessiné à de la 2D (dans un jeu 3D, cette fonction pourrait servir à dessiner le nombre de vie ou d'autre éléments 2D)
	glEnable(GL_TEXTURE_2D);														
}


/****************************************************************************
* Nom: reshape																*
* Description: redessinne la fenettre à tour de boucle glut					*
* IN: int (*2) pour la largeur et la hauteur de la fenetre					*
* OUT: void 																* 
* **************************************************************************/
void reshape(int w, int h){

	glViewport( 0, 0, w, h );													// modification des tailles
	glMatrixMode (GL_PROJECTION);												// pile courante == projection
	glLoadIdentity ();															// matrice identité en spécification de la projection
	gluOrtho2D(0, 625, 650, 0);
	glMatrixMode(GL_MODELVIEW);													// pile courante = point de vue
}
