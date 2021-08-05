#include "Cup.h"
#include <cmath>

Cup::Cup(){
	x = 0.0;
	y = 0.0;
	w = 0.1;
	h = 0.1;
	r = 0.0;
	g = 0.0;
	b = 1.0;
	Cupshape = new Rect(x, y, w, h, r, g, b);
	cupSprite = new TexRect("redCup.png", x, y, w, h);
}

Cup::Cup(float x, float y, float w, float h, float r, float g, float b) {
    this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->r = r;
	this->g = g;
	this->b = b;
	CupOutline = new Rect(x-0.004, y+0.003, w+0.008, h+0.008, 0, 0, 0);
	Cupshape = new Rect(this->x, this->y,this->w, this->h, this->r, this->g, this->b);
	cupSprite = new TexRect("redCup.png", this->x, this->y,this->w+0.05, this->h+0.05);
}

void Cup::draw() const {
	//CupOutline->draw();
	//Cupshape->draw();	
	cupSprite->draw();
}

bool Cup::contains(float x, float y) const{
	return Cupshape->contains(x,y);
}
