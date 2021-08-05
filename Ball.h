#ifndef Ball_H
#define Ball_H
#include "Circle.h"

class Ball{
	Circle* Ballshape;
	float x;
	float y;

	float radius;

	float r;
	float g;
	float b;

	bool isFlying;
	float destinationY;

public:
	Ball();
	Ball(float x, float y, float radius, float r, float g, float b);

	void draw() const;

	void advance();

	void playerLaunch(float x, float y, float power);
	void computerLaunch(float x, float y, float destinationY);

	float getY() const;
	float getX() const;
	bool reachedDestination();

	void setY(float y);
	void setX(float x);
	void setDestinationY(float y);
	void setIsFlying();

	float distanceToDestination();
	

	
};


#endif
