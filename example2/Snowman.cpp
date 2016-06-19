/*
 * Snowman.cpp
 *
 *  Created on: Apr 25, 2016
 *      Author: rossana
 */

#include "Snowman.h"

Snowman::Snowman() {
	// TODO Auto-generated constructor stub

}

Snowman::~Snowman() {
	// TODO Auto-generated destructor stub
}

/*
 * 	glEnable (GL_COLOR_MATERIAL);
	glColorMaterial (GL_FRONT, GL_DIFFUSE);

	// Draw Body
	glTranslatef(0.0f ,0.75f, 0.0f);
	glColor3f(1, 1, 1);
	glutSolidSphere(0.75f,20,20);

	// Draw Head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glColor3f(1, 1, 1);
	glutSolidSphere(0.25f,20,20);

	// Draw Eyes
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f,10,10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);
	glPopMatrix();

	// Draw Nose
	glRotatef(0.0f,1.0f, 0.0f, 0.0f);
	glColor3f(1, 0.5, 0.5);
	glutSolidCone(0.08f,0.5f,10,2);

	glDisable(GL_COLOR_MATERIAL);
 */

void Snowman::drawSnowMan(){

	GLfloat eyes[] = {0, 0, 0};
	GLfloat body[] = {1, 1, 1};
	GLfloat nose[] = {1, 0.5, 0.5};

	// Draw Body
	glEnable(GL_COLOR_MATERIAL);
	glTranslatef(0.0f ,0.75f, 0.0f);
	glColor3f(1, 1, 1);
	glColorMaterial(GL_FRONT, GL_EMISSION);
	glutSolidSphere(0.75f,20,20);
	glDisable(GL_COLOR_MATERIAL);

	// Draw Head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glMaterialfv(GL_FRONT, GL_EMISSION, body);
	glutSolidSphere(0.25f,20,20);

	// Draw Eyes
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_EMISSION, eyes);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f,10,10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);
	glPopMatrix();

	// Draw Nose
	glRotatef(0.0f,1.0f, 0.0f, 0.0f);
	glMaterialfv(GL_FRONT, GL_EMISSION, nose);
	glutSolidCone(0.08f,0.5f,10,2);

}
