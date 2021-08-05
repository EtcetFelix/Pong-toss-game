#ifndef Game_h
#define Game_h

#include "Screen.h"
#include "MainScreen.h"
#include <vector>

class Game {

    Screen* currentScreen;

    public:
        Game();

        void draw() const;

        void keyDown(unsigned char key, float x, float y);

        void leftMouseDown(float x, float y);
        void leftMouseUp(float x, float y);

        void moveMouse(float x, float y);

        void advance();

        void idle();

};

#endif