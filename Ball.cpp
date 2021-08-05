#include "Ball.h"
#include <iostream>
#include <cmath>

Ball::Ball(){
	x = 0.0;
	y = 0.0;
	radius = 0.2;
	r = 0.0;
	g = 0.0;
	b = 1.0;
	Ballshape = new Circle(x, y, radius, r, g, b);
	isFlying = false;
	destinationY=y;
}

Ball::Ball(float x, float y, float radius, float r, float g, float b) {
    this->x = x;
	this->y = y;
	this->radius = radius;
	this->r = r;
	this->g = g;
	this->b = b;
	Ballshape = new Circle(x, y, radius, r, g, b);
	isFlying = false;
	destinationY=y;
}

void Ball::draw() const {
	Ballshape->draw();
}

float Ball::getY() const {return y;}
float Ball::getX() const {return x;}
bool Ball::reachedDestination() {
	float distanceToDestination = this->distanceToDestination();
	return distanceToDestination<=0.1;
}

void Ball::setY(float y) {
	this->y=y;
	Ballshape->setY(y);
}
void Ball::setX(float x) {
	this->x=x;
	Ballshape->setX(x);
}
void Ball::setDestinationY(float y) {
	destinationY = y;
}
void Ball::setIsFlying() {isFlying=true;}

void Ball::playerLaunch(float x, float y, float power){
	isFlying = true;
    destinationY = y + (power*5);
}

void Ball::computerLaunch(float x, float y, float power) {
	isFlying = true;
	destinationY = y - (power*5);
}



void Ball::advance() {
	if (isFlying && distanceToDestination()>0.1) {
		
		if(y>destinationY) {
			setY(y-0.1);
		}
		else {
			setY(y+0.1);
		}
	}
	else if(isFlying && distanceToDestination()<=0.1) {
		isFlying = false;
	}

}

float Ball::distanceToDestination() {
	return ( std::abs((destinationY-y)));	// return the magnitude of the distance to Destination
}