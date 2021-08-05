#ifndef App_h
#define App_h

#include <vector>
#include "Game.h"
#include "GlutApp.h"
#include "Rect.h"
#include "Circle.h"
#include "TexRect.h"

class App: public GlutApp {
    Game* game;
    int interval;

public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw() const;
    
    void keyDown(unsigned char key, float x, float y);
    
    void leftMouseDown(float x, float y);
    void leftMouseUp(float x, float y);

    void moveMouse(float x, float y);

    void advance();

    friend void timer(int id);
    
    ~App();
};

#endif
