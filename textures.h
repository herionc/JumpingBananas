/********************************************************************************************************************************************************************
*			Header File reprenant les "include", variables et prototypes en rapport avec l'incorporation des différentes textures utilisées dans le jeu				*
*			Projet: "Jumping Bananas modifié" dans le cadre de ma première année en Bachelier en sciences informatiques à l'université de Namur						*
*			Auteur: Christophe Hérion																																*
*************1******************************************************************************************************************************************************/

#ifndef TEXTURES_H
#define TEXTURES_H
#include <GL/glut.h>
#include <stdio.h>


//Inclusions des différentes textures converties en fichiers source .c par le programme "GIMP"
#include "ImgMurs.c"
#include "ImgSol.c"
#include "ImgPlateforme.c"
#include "ImgSinge.c"



/***************
*  Variables:  *
***************/
GLuint *textures;							// Pointeur du début de l'adresse du tableau d'entier Glut (GLuint) déclaré dans textures.c (Ce tableau sert à stocker toutes les textures du jeu)



/*****************************
*  Prototypes de fonctions:  *
*****************************/
void initTextures();						// Charge l'ensemble des textures 


// les prototypes ci-dessous correspondent aux fonctions servant à récupérer les textures du jeu à partir de images convertier en code source .c via GIMP:
void texture_1(GLuint texture);

void texture_2(GLuint texture);

void texture_3(GLuint texture);

void texture_4(GLuint texture);

#endif
