/*
 * Polygon.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: rossana
 */

#include "Polygon.h"

Polygon::Polygon(float *posizione, float *rettangolo, const char *img, bool alpha, bool isTri){//std::vector<float> posizione, std::vector<float> rettangolo, const char * img, bool alpha) {

	this->pos = posizione;
	this->rectangle = rettangolo;
	this->imgPath = img;
	this->alpha = alpha;
	this->isTri = isTri;

	util = new Utility();

	this->loadPolygonTexture();
}

Polygon::~Polygon() {
	cout << "Ho distrutto un poligono\n";

}


void Polygon::drawOnePolygon(){

	vector<float> uvCoord;
	int texCoord;
	GLfloat color[] = {1, 1, 1};

	if(isTri){
		texCoord = 3;
		uvCoord.push_back(0.0f);
		uvCoord.push_back(0.0f);
		uvCoord.push_back(1.0f);
		uvCoord.push_back(0.0f);
		uvCoord.push_back(0.5f);
		uvCoord.push_back(1.0f);
		//btm left, btm right, top
	} else{
		texCoord = 4;
		uvCoord.push_back(0.0f);
		uvCoord.push_back(1.0f);
		uvCoord.push_back(0.0f);
		uvCoord.push_back(0.0f);
		uvCoord.push_back(1.0f);
		uvCoord.push_back(0.0f);
		uvCoord.push_back(1.0f);
		uvCoord.push_back(1.0f);
		//btm left, top left, top right, btm right
	}


	glPushMatrix();
	glTranslatef(pos[0], pos[1], pos[2]);
	glMaterialfv(GL_FRONT, GL_SPECULAR, color);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if(isTri)
		glBegin(GL_TRIANGLES);
	else
		glBegin( GL_QUADS );

	int vCount = 0;
	for(int i = 0; i < texCoord * 2; i++){
		glTexCoord2f(uvCoord[i], uvCoord[i + 1]);
		i = i + 1;
		glVertex3f(rectangle[vCount], rectangle[vCount + 1], rectangle[vCount + 2]);
		vCount = vCount + 3;
	}

	glEnd();
	glPopMatrix();
}

void Polygon::loadPolygonTexture(){


	this->texture = util->setTexure(this->imgPath, alpha);

}
