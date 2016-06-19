/*
 * Map.h
 *
 *  Created on: Apr 26, 2016
 *      Author: rossana
 */

#ifndef MAP_H_
#define MAP_H_

#include "Polygon.h"

class Map {
public:
	int dim;
	const char * skyImg;
	Polygon *l1;
	Polygon *l2;
	Polygon *l3;
	Polygon *l4;
	Polygon *l5;
public:
	Map();
	virtual ~Map();
	void drawSky();
};

#endif /* MAP_H_ */
