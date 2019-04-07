#include "graphismes.h"


/************************************************************************
* Nom: dessineBloc														*
* Description: 	Dessine un carré sur lequel on va coller une texture	*
* IN: 8x GLint (pour les coordonnées) + 1 GLuint (pour la texture)		*
* OUT: void 															* 
* **********************************************************************/
void dessineBloc(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4, GLuint texture){
	
	glColor4f(1, 1, 1, 1);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture); 
	
	glBegin(GL_QUADS);
    	glTexCoord2d(0.0, 0.0); glVertex2i(x1, y1);								// Association des coordonnées 2D (glTexCoord2D) et dessins désiré 
    	glTexCoord2d(0.0, 1.0); glVertex2i(x2, y2);
		glTexCoord2d(1.0, 1.0); glVertex2i(x3, y3);
    	glTexCoord2d(1.0, 0.0); glVertex2i(x4, y4);


	glEnd();

	glDisable(GL_TEXTURE_2D);
}


/************************************************************************
* Nom: afficheMap														*
* Description: 	Affiche la map extraite du fichier "map.txt" par 		*
*				la fonction	lireMap() codée dans le module "map.c" 		*
* IN: void																*
* OUT: void 															*
* **********************************************************************/
void afficheMap(){

	GLuint textureMurs = textures[0];											// Variables de types GLuint permettant de récupérer les textures reprises dans le tableau textures
	GLuint textureSol = textures[1];
	GLuint texturePlateforme = textures[2];
	
	GLint x = 0; GLint y;
	int i = 0;
	int j = 0;

	for (j = 0; j < TAILLE; j++){

		y = TAILLE;

		for (i = 0; i < TAILLE; i++){

			if (map[i][j] == '1') 
				dessineBloc(x, y, x, y + TAILLE, x + TAILLE, y + TAILLE, x + TAILLE, y, textureMurs);

			if (map[i][j] == '2')
				dessineBloc(x, y, x, y + TAILLE, x + TAILLE, y + TAILLE, x + TAILLE, y, textureSol);

			if (map[i][j] == '3')
				dessineBloc(x, y, x, y + TAILLE, x + TAILLE, y + TAILLE, x + TAILLE, y, texturePlateforme);

			y += TAILLE;
		}

		x += TAILLE;	
	}
}


/****************************************************************************
* Nom: afficheSinge															*
* Description: 	Affiche le personnage principal								*
* IN: pointeur vers une structure de types "Personnages" (controleur.h)		*
* OUT: void 																*
* **************************************************************************/
void afficheSinge(Personnages *singe){
	
	singe->texture = textures[3];												// Assignation d'une texture à la variable texture de type GLuint faisant partie de la structure Personnages
	
	glColor4f(1, 1, 1, 1);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, singe->texture);
	
	
	glPushMatrix();

	glTranslatef(singe->posY*5.0, singe->posX * 10, 0.0);	
				
	glBegin(GL_QUADS);
   		glTexCoord2d(0.0, 1.0); glVertex2i(0.0 , 25.0);
    	glTexCoord2d(0.0, 0.0); glVertex2i(0.0 ,  0.0);
    	glTexCoord2d(1.0, 0.0); glVertex2i(25.0,  0.0);
    	glTexCoord2d(1.0, 1.0); glVertex2i(25.0, 25.0);
   	glEnd();

   	glPopMatrix();
	
    glDisable(GL_TEXTURE_2D);    
}

/************************************************************************
* Nom: affichage														*
* Description: 	Affiche ce que l'on souhaite. Est utilisée en argument  *
*				dans la fonction glutDisplayFunc (main.c)		 		*
* IN: void																*
* OUT: void 															*
* **********************************************************************/
void affichage(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	afficheMap();	

	afficheSinge(&(jeu.singe));

	glutSwapBuffers();
}
