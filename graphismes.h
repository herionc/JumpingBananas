/************************************************************************************************************************************
*			Header File reprenant les "include", variables et prototypes en rapport avec la partie graphique du jeu					*
*			Projet: Jumping Bananas "modifié" dans le cadre de ma première année en Bachelier en sciences informatiques				*
*			Auteur: Christophe Hérion																								*
*************1**********************************************************************************************************************/
#ifndef GRAPHISMES_H
#define GRAPHISMES_H

#include <string.h>
#include "controleur.h"
#include "textures.h"
#include <GL/freeglut.h>



/*****************************
*  Prototypes de fonctions:  *
*****************************/

void dessineBloc(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4, GLuint texture);

void afficheMap();

void afficheSinge(Personnages *singe);

void affichage();

#endif