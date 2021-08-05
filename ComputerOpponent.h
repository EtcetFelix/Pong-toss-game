#ifndef ComputerOpponent_H
#define ComputerOpponent_H

#include "Sprite.h"

class ComputerOpponent{
	float x;
	float y;

	Sprite* sprite;

	bool shooting;

public:
	ComputerOpponent();
	ComputerOpponent(float x, float y);
	

	void draw() const;

	void advance();
	void shootAdvance();

	void shoot();

	bool shootingDone();

	void setY(float y);

	void setX(float x);

	float getY() const;
	float getX() const;

};


#endif