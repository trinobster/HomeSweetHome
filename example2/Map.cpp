/*
 * Map.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: rossana
 */

#include "Map.h"
#include "Polygon.h"

Map::Map() {
	dim = 10;
	float p1[] = {0, 0, -dim};
	float r1[] = {-dim, 0, 0,
				 -dim, dim, 0,
				 dim, dim, 0,
				 dim, 0, 0};

	float p2[] = {-dim, 0, 0};
	float r2[] = {0, 0, dim,
				 0, dim, dim,
				 0, dim, -dim,
				 0, 0, -dim};

	float p3[] = {0, 0, dim};
	float r3[] = {-dim, 0, 0,
				 -dim, dim, 0,
				 dim, dim, 0,
				 dim, 0, 0};

	float p4[] = {10, 0, 0};
	float r4[] = {0, 0, dim,
				  0, dim, dim,
				  0, dim, -dim,
				  0, 0, -dim};

	float p5[] = {-dim, dim/2, 0};
	float r5[] = {0, dim/2, -dim,
				  2 * dim, dim/2, -dim,
				  2 * dim, dim/2, dim,
				  0, dim/2, dim};

	skyImg = "cielo.jpg";
/*
	l1 = new Polygon(p1, r1, skyImg, false);
	l2 = new Polygon(p2, r2, skyImg, false);
	l3 = new Polygon(p3, r3, skyImg, false);
	l4 = new Polygon(p4, r4, skyImg, false);
	l5 = new Polygon(p5, r5, skyImg, false);
*/

}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

void Map::drawSky(){
	l1->drawOnePolygon();
	l2->drawOnePolygon();
	l3->drawOnePolygon();
	l4->drawOnePolygon();
	l5->drawOnePolygon();
}

