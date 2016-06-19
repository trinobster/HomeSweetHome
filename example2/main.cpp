#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include "Pine.h"
#include "Camera.h"

using namespace std;

const int width = 640;
const int height = 480;
const GLfloat w = 10.0;

const GLfloat light_pos[] = {10, 20, 0};
const GLfloat light_ambient[] = {1, 1, 1};
Camera *camera;

// ----------------------------------------------------------------------- PARAMETRI CARTELLO
const char *pathStick = "signboard.jpg", *pathSign = "pole.jpg";
float palo = 0.2, cartello = 0.4;
float posStick[] = {-10, 0, 0}, posSign[] = {-10.1, 6 * palo, 0.001},
	  rectStick[] = {-palo, 0, 0,
			  	  	 -palo, 10 * palo, 0,
			  	  	 0, 10 * palo, 0,
			  	  	 0, 0, 0},
	  rectSign[] = {-cartello, 0, 0,
					-cartello, cartello * 2, 0,
					cartello, cartello * 2, 0,
					cartello, 0, 0};
Polygon *stick, *sign;

// ----------------------------------------------------------------------- PARAMETRI ALBERI
float posPine1[] = {5, 2.3, -5}, posPine2[] = {7, 2.3, -5},
	  rectPine[] = {-2.3, -2.3, 0,
			  	  	-2.3, 2.3, 0,
			  	  	2.3, 2.3, 0,
			  	  	2.3, -2.3, 0};
const char *pathPine1 = "pine-tree.png", *pathPine2 = "pine.png";
Pine *pine1, *pine2;

// ----------------------------------------------------------------------- PARAMETRI CIELO E TERRA
int dim = 30;
const char * pathGround = "ground2.jpg", * pathUp = "upnight.jpg", * path = "night.jpg";
float p1[] = {0, 0, -dim}, p2[] = {-dim, 0, 0}, p3[] = {0, 0, dim}, p4[] = {dim, 0, 0}, p5[] = {-dim, dim/2, 0}, p[] = {-dim, 0, 0};
float r1[] = {-dim, 0, 0,
			 -dim, dim, 0,
			 dim, dim, 0,
			 dim, 0, 0},

	  r2[] = {0, 0, dim,
			  0, dim, dim,
			  0, dim, -dim,
			  0, 0, -dim},

	  r3[] = {-dim, 0, 0,
			  -dim, dim, 0,
			  dim, dim, 0,
			  dim, 0, 0},

	  r4[] = {0, 0, dim,
			  0, dim, dim,
			  0, dim, -dim,
			  0, 0, -dim},

	  r5[] = {0, dim/2, -dim,
			  2 * dim, dim/2, -dim,
			  2 * dim, dim/2, dim,
			  0, dim/2, dim},
	  r[] = {0, 0, -dim,
			 2 * dim, 0, -dim,
			 2 * dim, 0, dim,
			 0, 0, dim};

Polygon *l1, *l2, *l3, *l4, *l5, *g;

// ----------------------------------------------------------------------- PARAMETRI LATI CASA
float lato = 2.7;
const char * pathSide = "side.jpg", *pathWindow = "window.jpg";
float po1[] = {0, 0, -lato}, po2[] = {-lato, 0, 0}, po3[] = {0, 0, lato}, po4[] = {lato, 0, 0};
float re1[] = {-lato, 0, 0,
			 -lato, lato, 0,
			 lato, lato, 0,
			 lato, 0, 0},

	  re2[] = {0, 0, lato,
			  0, lato, lato,
			  0, lato, -lato,
			  0, 0, -lato},

	  re3[] = {-lato, 0, 0,
			  -lato, lato, 0,
			  lato, lato, 0,
			  lato, 0, 0},

	  re4[] = {0, 0, lato,
			  0, lato, lato,
			  0, lato, -lato,
			  0, 0, -lato};
Polygon *lato1, *lato2, *lato3, *lato4;

// ----------------------------------------------------------------------- PARAMETRI PORTA
float door = lato / lato;
const char *pathDoor = "door.jpg";
float position[] = {0, 0, lato + 0.001}, rect[] = {-door * 0.65, 0, 0,
												  -door * 0.65, 1.6 * door, 0,
												   door * 0.65, 1.6 * door, 0,
												   door * 0.65, 0, 0};
Polygon *porta;

// ----------------------------------------------------------------------- PARAMETRI TETTO
const char *pathRoof = "roof.png";
float posRoof1[] = {0, lato, -lato}, posRoof2[] = {-lato, lato, 0}, posRoof3[] = {0, lato, lato}, posRoof4[] = {lato, lato, 0},

		rectRoof1[] = {-lato,0, 0,
					  lato, 0, 0,
					  0, lato, lato},
		rectRoof2[] = {0, 0, lato,
					   0, 0, -lato,
					   lato, lato, 0},
		rectRoof3[] = {-lato,0, 0,
						lato, 0, 0,
						0, lato, -lato},
		rectRoof4[] = {0, 0, lato,
					   0, 0, -lato,
					  -lato, lato, 0};
Polygon *t1, *t2, *t3, *t4;

// ----------------------------------------------------------------------- PARAMETRI LAGO
const char *pathDeep = "deeplake.jpg";
int lago = 20;
float posDeep[] = {0 + 0.001, 0 + 0.001, -dim + 0.001},
	  rectDeep[] = {dim, 0, 0,
				 dim, 0, lago,
				 -dim, 0, lago,
				 -dim, 0, 0};
Polygon *deepLake;

void init(){

	camera = new Camera();

	// SETTA PARAMETRI CIELO E TERRA
	l1 = new Polygon(p1, r1, path, false, false);
	l2 = new Polygon(p2, r2, path, false, false);
	l3 = new Polygon(p3, r3, path, false, false);
	l4 = new Polygon(p4, r4, path, false, false);
	l5 = new Polygon(p5, r5, pathUp, false, false);
	g = new Polygon(p, r, pathGround, false, false);

	// SETTA PARAMETRI LATI CASA e PORTA
	lato1 = new Polygon(po1, re1, pathSide, false, false);
	lato2 = new Polygon(po2, re2, pathWindow, false, false);
	lato3 = new Polygon(po3, re3, pathSide, false, false);
	lato4 = new Polygon(po4, re4, pathWindow, false, false);
	porta = new Polygon(position, rect, pathDoor, false, false);

	// SETTA PARAMETRI TETTO

	t1 = new Polygon(posRoof1, rectRoof1, pathRoof, true, true);
	t2 = new Polygon(posRoof2, rectRoof2, pathRoof, true, true);
	t3 = new Polygon(posRoof3, rectRoof3, pathRoof, true, true);
	t4 = new Polygon(posRoof4, rectRoof4, pathRoof, true, true);

	// SETTA PARAMETRI ALBERI
	pine1 = new Pine(posPine1, rectPine, pathPine1, true, false);
	pine2 = new Pine(posPine2, rectPine, pathPine2, true, false);


	// SETTA PARAMETRI CARTELLO
	stick = new Polygon(posStick, rectStick, pathStick, false, false);
	sign = new Polygon(posSign, rectSign, pathSign, false, false);

	// SETTA PARAMETRI LAGO
	deepLake = new Polygon(posDeep, rectDeep, pathDeep, false, false);

	// Luci
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat lightAmbient[] = {0.5, 0.5, 0.5, 1.0 };
	GLfloat lightDiffuse[] = { 0.5, 0.5, 0.5, 1 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_ambient);

	glMaterialfv(GL_FRONT, GL_AMBIENT, lightAmbient); // illumina meglio

	// Alpha Channel
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0f);
}

void display(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera->setCamera();

	// DISEGNA CIELO e TERRA
	l1->drawOnePolygon();
	l2->drawOnePolygon();
	l3->drawOnePolygon();
	l4->drawOnePolygon();
	l5->drawOnePolygon();
	g->drawOnePolygon();

	// DISEGNA LATI CASA
	lato1->drawOnePolygon();
	lato2->drawOnePolygon();
	lato3->drawOnePolygon();
	lato4->drawOnePolygon();

	// DISEGNA PORTA
	porta->drawOnePolygon();

	// DISEGNA TETTO
	t1->drawOnePolygon();
	t2->drawOnePolygon();
	t3->drawOnePolygon();
	t4->drawOnePolygon();

	// DISEGNA ALBERI
	glPushMatrix();
	for(int i = 1; i < 6; i++){
		pine1->drawPine();
		glTranslatef(2, 0, 2);
		pine2->drawPine();
		//glTranslatef(-28, 0, 5);
		glTranslatef(2, 0, 2);
		//drawSnowMan();
	}
	glPopMatrix();

	//DISEGNA CARTELLO
	stick->drawOnePolygon();
	sign->drawOnePolygon();

	// DISEGNA LAGO
	deepLake->drawOnePolygon();

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){

	camera->processNormalKeys(key, x, y);
}

void specialKeys(int key, int x, int y){

	camera->processSpecialKeys(key, x, y);
}

void reshape(int w, int h){

	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w/(GLfloat)h, 1.0, 100.0);
}

int main(int argc, char** argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("FCG03: move with WASD and arrows");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);

	glutMainLoop();

	return 0;
}
