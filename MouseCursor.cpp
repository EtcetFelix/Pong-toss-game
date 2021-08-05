#include <iostream>
#include "MouseCursor.h"


MouseCursor::MouseCursor(float x, float y){
    this->x = x;
    this->y = y;
    //heldCursor = new Rect(x, y, 0.05, 0.05, 0, 204.0/255, 1);
    holdingClick = false;
    powerBar = new Rect(x,y, 0.05, 0.05, 0, 204.0/255, 1);
    cursor = new Sprite("hand.png", 3, 4, x, y, 0.4, 0.4);
    cursor->setSprite(3,1);
} 

void MouseCursor::draw() const {
    if(holdingClick) {
        //heldCursor->draw();
        powerBar->draw();
    }
        cursor->draw();
}

void MouseCursor::keyDown(unsigned char key, float x, float y){

}

void MouseCursor::leftMouseDown(float x, float y) {
    holdingClick = true;
    cursor->setSprite(1, 1);
    changePos(x,y);
    resetPowerBar();
}

void MouseCursor::leftMouseUp(float x, float y) {
    cursor->setSprite(3,1);
    holdingClick = false;
    changePos(x,y);
}



void MouseCursor::changePos(float x, float y) {
    this->x = x;
    this->y = y;
    cursor->setX(x-0.2);
    cursor->setY(y+0.2);
    //heldCursor->setX(x);
    //heldCursor->setY(y);
    powerBar->setX(x+0.075);
    powerBar->setY(y-0.04);
}

void MouseCursor::resetPowerBar() {
    powerBar->setH(0.01);
}

void MouseCursor::advance() {
    if(holdingClick) {
        if((powerBar->getH()) < 0.2) {
            powerBar->setH(powerBar->getH()+0.01);
            powerBar->setY(powerBar->getY()+0.01);
        }
        else {
            powerBar->setH(0.01);
            powerBar->setY(cursor->getY()-0.04);
        }
    }
}

float MouseCursor::getPowerBarH() const{return powerBar->getH();}
float MouseCursor::getY() const{return y;}
float MouseCursor::getX() const{return x;}

MouseCursor::~MouseCursor(){   

}
