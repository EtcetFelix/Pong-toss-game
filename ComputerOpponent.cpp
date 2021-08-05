#include "ComputerOpponent.h"
#include <iostream>

ComputerOpponent::ComputerOpponent(){
	x = 0.0;
	y = 0.0;
    sprite = new Sprite("BPOpponent.png", 2, 6, x, y, 0.45, 0.7);
	shooting=false;
}

ComputerOpponent::ComputerOpponent(float x, float y) {
    this->x = x;
	this->y = y;
    sprite = new Sprite("BPOpponent.png", 2, 6, x, y, 0.45, 0.7);
	sprite->setEndSprite(2, 2);
}

void ComputerOpponent::advance() {
	if(shooting && !(sprite->reachedLastSprite())) {
		
		shootAdvance();
	}
	else if(shooting && sprite->reachedLastSprite()) {
		shooting = false;
		sprite->setSprite(1,1);
	}
}

void ComputerOpponent::shootAdvance() {
	sprite->advance();
}

void ComputerOpponent::shoot() {
	shooting = true;
}

bool ComputerOpponent::shootingDone(){
	return !shooting;
}

void ComputerOpponent::draw() const {
	sprite->draw();
}

void ComputerOpponent::setY(float y){
	this-> y = y;
    sprite->setY(y);
}

void ComputerOpponent::setX(float x){
	this-> x = x;
    sprite->setX(x);
}

float ComputerOpponent::getY() const{
	return y;
}

float ComputerOpponent::getX() const {
	return x;
}
