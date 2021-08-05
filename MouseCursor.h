#ifndef MouseCursor_h
#define MouseCursor_h

#include <vector>
#include "Rect.h"
#include "Circle.h"
#include "Sprite.h"

class MouseCursor{
    float x;
    float y;
    Sprite* cursor;
    //Sprite* heldCursor;
    Rect* powerBar;
    bool holdingClick;


public:
    
    MouseCursor(float x, float y);
    
    void draw() const;
    
    void leftMouseDown(float x, float y);
    void leftMouseUp(float x, float y);

    void keyDown(unsigned char key, float x, float y);

    void changePos(float x, float y);

    void resetPowerBar();

    float getPowerBarH() const;
    float getY() const;
    float getX() const;

    void advance();
    
    ~MouseCursor();
};

#endif
