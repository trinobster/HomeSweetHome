/*
 * Polygon.h
 *
 *  Created on: Apr 26, 2016
 *      Author: rossana
 */

#ifndef POLYGON_H_
#define POLYGON_H_

#include "Utility.h"
#include <vector>
#include <string>

using namespace std;

class Polygon {
public:
	//std::vector<float> pos;
	//std::vector<float> rectangle; // btm left; top left; top right; btm right;
	float *pos;
	float *rectangle;
	const char * imgPath;
	GLuint texture;
	bool alpha;
	bool isTri;
	Utility *util;

public:
	//Polygon(std::vector<float> posizione, std::vector<float> rettangolo, const char * img, bool alpha);
	Polygon(float *posizione, float *rettangolo, const char *img, bool alpha, bool isTri);
	virtual ~Polygon();

	void drawOnePolygon();
	void loadPolygonTexture();
};
#endif /* POLYGON_H_ */
