/*
 * Camera.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: rossana
 */


#include "Camera.h"
#include <math.h>
#include <iostream>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

float limite = 5.0;

Camera::Camera() {

	r = 5;

	angoloOrizzontale = 0;
	angoloVerticale = 0;

	x = -10;
	y = 3;
	z = -5;

	lookX = 0;
	lookY = 0;
	lookZ = 1;
}

void Camera::setCamera(){

	gluLookAt(x,y,z,
			lookX + x, lookY + y, lookZ + z,
			0,1,0);
}

void Camera::processNormalKeys(unsigned char key, int xx, int yy){

	float avanza = 0.5f;

	float posizioneX_temp = x;
	float posizioneZ_temp = z;

	switch (key) {

		case 27:
			exit(0);
			break;

		case 'w' :
			posizioneZ_temp += avanza * cos(angoloOrizzontale);
			posizioneX_temp += avanza * sin(angoloOrizzontale);
			break;

		case 's' :
			posizioneZ_temp -= avanza * cos(angoloOrizzontale);
			posizioneX_temp -= avanza * sin(angoloOrizzontale);
			break;

		case 'a' :
			posizioneZ_temp -= avanza * sin(angoloOrizzontale);
			posizioneX_temp += avanza * cos(angoloOrizzontale);
			break;

		case 'd' :
			posizioneZ_temp += avanza * sin(angoloOrizzontale);
			posizioneX_temp -= avanza * cos(angoloOrizzontale);
			break;

		default:
			break;
	}

	if((posizioneX_temp > 29) || (posizioneX_temp < -29) || (posizioneZ_temp > 29) || (posizioneZ_temp < -9)){
		// non posso uscire dalla box e non posso entrare nel lago
	} else if((posizioneX_temp > -4) && (posizioneX_temp < 3.8) && (posizioneZ_temp >= -4) && (posizioneZ_temp < 3.8)){
		// non posso entrare nella casetta
	} else {
			x = posizioneX_temp;
			z = posizioneZ_temp;
			// la telecamera si muove
		}
}

void Camera::processSpecialKeys(int key, int xx, int yy){

	float angoloVerticale_temp = angoloVerticale;

	switch (key) {
		case GLUT_KEY_LEFT :
			angoloOrizzontale += 0.1f;
			break;

		case GLUT_KEY_RIGHT :
			angoloOrizzontale -= 0.1f;
			break;

		case GLUT_KEY_UP :
			angoloVerticale_temp += 0.1f;
			break;

		case GLUT_KEY_DOWN :
			angoloVerticale_temp -= 0.1f;
			break;

		default:
				break;
	}

	lookX = r * sin(angoloOrizzontale);

	lookZ = r * cos(angoloOrizzontale);
	if(angoloVerticale_temp<-M_PI/2||angoloVerticale_temp>M_PI/2)
	{
		//stai invertendo su e giu
	}
	else
	{
		angoloVerticale=angoloVerticale_temp;
		lookY = r * sin(angoloVerticale);

	}

}
Camera::~Camera() {
	// TODO Auto-generated destructor stub
}
