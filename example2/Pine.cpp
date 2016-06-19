/*
 * Pine.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: rossana
 */

#include "Pine.h"

Pine::Pine(float *posizione, float *rettangolo, const char *img, bool alpha, bool isTri) : Polygon(posizione, rettangolo, img, alpha, false){//(vector<float> posizione, vector<float> rettangolo, const char * img, bool alpha) : Polygon(posizione, rettangolo, img, alpha) {

}

void Pine::drawPine(){

	drawOnePolygon();

	glPushMatrix();
	glTranslatef(pos[0], pos[1], pos[2]); //(pos.at(0), pos.at(1), pos.at(2));
		glRotatef(80, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBegin( GL_QUADS );
	glTexCoord2f( 0.0f, 1.0f );

	glVertex3f( rectangle[0], rectangle[1], rectangle[2] ); //( rectangle.at(0), rectangle.at(1), rectangle.at(2) );
	//btm left
	glTexCoord2f( 0.0f, 0.0f );
	glVertex3f( rectangle[3], rectangle[4], rectangle[5]); //( rectangle.at(3), rectangle.at(4), rectangle.at(5));
	//top left
	glTexCoord2f( 1.0f, 0.0f );
	glVertex3f( rectangle[6], rectangle[7], rectangle[8] ); //( rectangle.at(6), rectangle.at(7), rectangle.at(8) );
		//top right
	glTexCoord2f( 1.0f, 1.0f );
	glVertex3f( rectangle[9], rectangle[10], rectangle[11] ); //( rectangle.at(9), rectangle.at(10), rectangle.at(11) );
		//btm right

	glEnd();
	glPopMatrix();
}

Pine::~Pine() {

}

