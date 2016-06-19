/*
 * Utility.h
 *
 *  Classe in cui verranno salvati alcuni metodi utili comuni
 *
 *  Created on: Mar 31, 2016
 *      Author: rossana
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>


#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Utility {
public:
	Utility();
	virtual ~Utility();
	GLuint loadTexture(SDL_Surface* image, GLint level, GLint internalFormat, GLenum format, GLenum type);
	GLuint setTexure(const char * imgPath, bool alpha); // SDL_Surface * surface,
};

#endif /* UTILITY_H_ */
