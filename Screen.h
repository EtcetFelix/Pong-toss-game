#ifndef Screen_h
#define Screen_h

#include <vector>
#include "GlutApp.h"
#include "Rect.h"
#include "Circle.h"
#include "TexRect.h"

class Screen{

std::vector<Shape*> shapes;

public:
    
    Screen();
    
    virtual void draw() const;
    
    virtual void keyDown(unsigned char key, float x, float y);

    virtual void leftMouseDown(float x, float y);
    virtual void leftMouseUp(float x, float y);

    virtual void moveMouse(float x, float y);

    virtual void advance();

    virtual bool shouldChangeToNextScreen();

    virtual Screen* nextScreen();
    
    virtual ~Screen();
};

#endif
