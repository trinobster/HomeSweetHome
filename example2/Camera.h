/*
 * Camera.h
 *
 *  Created on: Apr 29, 2016
 *      Author: rossana
 */

#ifndef CAMERA_H_
#define CAMERA_H_

using namespace std;

class Camera {
public:
	float r;
	float angoloOrizzontale, angoloVerticale;
	float x, y, z;
	float lookX, lookY, lookZ;
public:
	Camera();
	void setCamera();
	void processNormalKeys(unsigned char key, int xx, int yy);
	void processSpecialKeys(int key, int xx, int yy);
	virtual ~Camera();
};

#endif /* CAMERA_H_ */
