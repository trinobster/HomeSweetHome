/*
 * Utility.cpp
 *
 *  Created on: Mar 31, 2016
 *      Author: rossana
 */

#include "Utility.h"

Utility::Utility(){

};

Utility::~Utility() {

}

GLuint Utility::setTexure(const char * imgPath,  bool alpha){ //SDL_Surface * surface,

	GLuint texture;
	GLint rgb;
	SDL_Surface *surface;

	glEnable(GL_TEXTURE_2D);
	surface = IMG_Load(imgPath);

	if (surface == NULL) {
		printf("Unable to load image: %s\n", SDL_GetError());
		exit(0);
	}

	if(alpha){
		rgb = GL_RGBA;
	} else{
		rgb = GL_RGB;
	}

	texture = this->loadTexture(surface, 0, rgb, rgb, GL_UNSIGNED_BYTE);
	delete surface;

	return texture;
}

GLuint Utility::loadTexture(SDL_Surface* image, GLint level, GLint internalFormat, GLenum format, GLenum type){

	GLuint texName;
	glGenTextures(1, &texName);
	glBindTexture(GL_TEXTURE_2D, texName);
	glTexImage2D(GL_TEXTURE_2D,
				 level,
				 internalFormat,
				 image->w,
				 image->h,
				 0,
				 format,
				 type,
				 image->pixels);

	return texName;
};

