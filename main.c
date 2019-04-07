#include "controleur.h"
#include "graphismes.h"
#include <stdio.h>



int main(int argc, char **argv){
	
	/*************************************	
	*    Fonctions "d'initialisation"    *
	*************************************/
	
	glutInit (&argc, argv);  													// Permet d'initialiser Glut par rapport aux arguments de la fonction "main"
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);					// Initialisation du mode de la fenêtre (GLUT_DOUBLE == double buffer et GLUTR_RGBA == permet d'utiliser le mode RGBA (A pour alphe, permet d'utiliser la profondeur, la 3D)
	glutInitWindowSize (625 , 625); 											// Donne la possibilité d'entrer des entiers en arguments pour attribuer une taille à notre fénêtre
	glutInitWindowPosition(650, 200);											// Permet de donner une position centrale de notre fenêtre à l'écran
	glutCreateWindow ("Jumping Bananas");										// Crée la fenêtre et l'argument de type string lui donne un nom

	
	/*******************************	
	*   Fonctions de "Callback":   *
	*******************************/


	initOpenGL();																// Appel à InitOpenGL() qui détermine la couleur de fond de map, lit la map, charge les textures etc...
	glutDisplayFunc(affichage);													// Envoie les parametres graphiques à l'écran via la fonction "affichage" utilisée en argument
	glutReshapeFunc(reshape);													// Appel de glutReshapeFunc() qui prend la fonction reshape en argument (que j'ai repris d'internet)
	glutKeyboardFunc(keyboard);													// Active la possibilité de gérer le clavier via la fonction keyboard utilisée en argument 
	

	glutMainLoop();																// Fin de boucle

	return 0;
}


	
	


