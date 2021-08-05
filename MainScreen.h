#ifndef MainScreen_h
#define MainScreen_h

#include <vector>
#include "MouseCursor.h"
#include "Ball.h"
#include "Cup.h"
#include "Screen.h"
#include "GlutApp.h"
#include "Rect.h"
#include "Circle.h"
#include "TexRect.h"
#include "Sprite.h"
#include "ComputerOpponent.h"


class MainScreen: public Screen{
std::vector<Shape*> shapes;
std::vector<Cup*> playerCups;
std::vector<Cup*> opponentCups;
Ball* ball;
MouseCursor* cursor;
//Sprite* opponent;
ComputerOpponent* opponent;
Sprite* twerkingGirl;
Sprite* DancingGuy;
bool ballIsFlying;
float ballDestination;
TexRect* background;
TexRect* table;

bool playerTurn;
bool havntShot;
bool ballFlying;

public:
    
    MainScreen();
    
    void draw() const;
    
    void keyDown(unsigned char key, float x, float y);
    
    void leftMouseDown(float x, float y);
    void leftMouseUp(float x, float y);

    void moveMouse(float x, float y);

    void advance();

    void switchTurns();

    float RandomFloat(float a, float b);

    void computerLaunch();

    void launchBall(float x, float y, float power);

    bool hitCup(float x, float y);

    bool noPlayerCupsLeft();
    bool noOpponentCupsLeft();

    bool shouldChangeToNextScreen();

    Screen* nextScreen();
    
    ~MainScreen();
};

#endif
