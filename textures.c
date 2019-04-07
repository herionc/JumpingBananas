#include "textures.h"

/********************************************************
* Nom: init_Textures								    *
* Date: 11/03/2019									    *
* Description: 	Charge les différentes 	        		*
* 				textures dans un tableau de Textures    *
* ******************************************************/
void initTextures(){

	textures = malloc(4*sizeof(GLuint));

  glGenTextures(4, textures);

	texture_1(textures[0]);
	texture_2(textures[1]);
	texture_3(textures[2]);
 	texture_4(textures[3]);

}



/****************************************************************************************************************************************
* Toutes les fonctions ci-dessous servent a récupérer 1 textures selon une méthode dont la source provient du site internet suivant:	*
* http://timmurphy.org/2009/07/07/adding-images-to-opengl-in-c/															           		*    
* Chacune des textures est convertie en un fichier source .c par le programme GIMP puis est chargée dans un tableau de textures avant	* 
* d'être collée sur dessin (carré) créé via OpenGL    																		            *
****************************************************************************************************************************************/

// Textures des murs de la map:
void texture_1(GLuint texture){

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture);

  glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE , GL_MODULATE);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    gluBuild2DMipmaps(GL_TEXTURE_2D, ImgPlateforme.bytes_per_pixel, ImgPlateforme.width, ImgPlateforme.height, GL_RGBA, GL_UNSIGNED_BYTE, ImgPlateforme.pixel_data);

    glDisable(GL_TEXTURE_2D);
}


// Textures du sol de la map:
void texture_2(GLuint texture){

	glEnable(GL_TEXTURE_2D);
 	glBindTexture(GL_TEXTURE_2D, texture);

	glEnable(GL_BLEND);
  	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE , GL_MODULATE);

  	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
  	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  	gluBuild2DMipmaps(GL_TEXTURE_2D, ImgSol.bytes_per_pixel, ImgSol.width, ImgSol.height, GL_RGBA, GL_UNSIGNED_BYTE, ImgSol.pixel_data);

  	glDisable(GL_TEXTURE_2D);
}

// Textures des plateformes de la map:
void texture_3(GLuint texture){

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture);

  glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE , GL_MODULATE);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    gluBuild2DMipmaps(GL_TEXTURE_2D, ImgMurs.bytes_per_pixel, ImgMurs.width, ImgMurs.height, GL_RGBA, GL_UNSIGNED_BYTE, ImgMurs.pixel_data);

    glDisable(GL_TEXTURE_2D);
}

// Textures du personnage principal (singe):
void texture_4(GLuint texture){

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture);

  glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE , GL_MODULATE);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    gluBuild2DMipmaps(GL_TEXTURE_2D, ImgSinge.bytes_per_pixel, ImgSinge.width, ImgSinge.height, GL_RGBA, GL_UNSIGNED_BYTE, ImgSinge.pixel_data);

    glDisable(GL_TEXTURE_2D);
}
