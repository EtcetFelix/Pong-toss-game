#ifndef Cup_H
#define Cup_H
#include "Rect.h"
#include "Sprite.h"

class Cup{
	Rect* Cupshape;
	Rect* CupOutline;
	TexRect* cupSprite;
	float x;
	float y;

	float w;
	float h;

	float r;
	float g;
	float b;

public:
	Cup();
	Cup(float x, float y, float w, float h, float r, float g, float b);

	void draw() const;

	bool contains(float x, float y) const;
};


#endif
