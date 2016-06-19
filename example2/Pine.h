/*
 * Pine.h
 *
 *  Created on: Apr 25, 2016
 *      Author: rossana
 */

#ifndef PINE_H_
#define PINE_H_

#include "Polygon.h"

using namespace std;

class Pine : public Polygon{
public:
	//std::vector<float> pos;
	//std::vector<float> rectangle; // btm left; top left; top right; btm right;
	//const char * imgPath;
	//GLuint texture;

public:
	Pine(float *posizione, float *rettangolo, const char *img, bool alpha, bool isTri);//(std::vector<float> posizione, std::vector<float> rettangolo, const char * img, bool alpha);
	virtual ~Pine();
	//void drawOnePine();
	void drawPine();
	//void loadPineTexture();
};

#endif /* PINE_H_ */
