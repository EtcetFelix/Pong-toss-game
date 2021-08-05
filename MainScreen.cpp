#include <iostream>
#include "MainScreen.h"
#include <cstdlib>
#include "WinningScreen.h"
#include "LosingScreen.h"


MainScreen::MainScreen() : Screen(){
    //background 
    background = new TexRect("partyBackgroundCropped.png", -1, 1, 2, 2);

    shapes.push_back(new Rect(-0.25, 0.4, 0.5, 0.9, 1, 1, 1));       // table
    ball = new Ball(-0.125, -0.25, 0.03125, 0, 1, 0);     // ball

    // opponent cups
    opponentCups.push_back(new Cup(0.05, 0.35, 0.0625, 0.125, 1, 0, 0));     // 3rd row right cup
    opponentCups.push_back(new Cup(-0.109, 0.35, 0.0625, 0.125, 1, 0, 0));      // 3rd row left cup
    opponentCups.push_back(new Cup(-0.03125, 0.35, 0.0625, 0.125, 1, 0, 0));      // 3rd row mid cup
    opponentCups.push_back(new Cup(.004, 0.275, 0.0625, 0.125, 1, 0, 0));      // 2nd row right cup
    opponentCups.push_back(new Cup(-.07, 0.275, 0.0625, 0.125, 1, 0, 0));      //2nd row left cup
    opponentCups.push_back(new Cup(-0.03125, 0.2125, 0.0625, 0.125, 1, 0, 0));     //opponent 1st cup

    // player cups
    playerCups.push_back(new Cup(-0.03125, -0.2, 0.0625, 0.125, 1, 0, 0));     //opponent 1st cup
    playerCups.push_back(new Cup(.004, -0.28, 0.0625, 0.125, 1, 0, 0));      // 2nd row right cup
    playerCups.push_back(new Cup(-.07, -0.28, 0.0625, 0.125, 1, 0, 0));      //2nd row left cup
    playerCups.push_back(new Cup(0.05, -0.35, 0.0625, 0.125, 1, 0, 0));     // 3rd row right cup
    playerCups.push_back(new Cup(-0.03125, -0.35, 0.0625, 0.125, 1, 0, 0));      // 3rd row mid cup
    playerCups.push_back(new Cup(-0.109, -0.35, 0.0625, 0.125, 1, 0, 0));      // 3rd row left cup
    
    cursor = new MouseCursor(0,0);
    opponent = new ComputerOpponent(-0.1,0.9);              // Opponent

    DancingGuy = new Sprite("GuyDancing.png", 2, 3, -0.99, 0.1, 0.94, 0.94);

    playerTurn = true;
    havntShot = true;
    ballFlying = false;
} 

void MainScreen::draw() const {
    background->draw();
    DancingGuy->draw();
    opponent->draw();
    for(auto i = shapes.begin(); i != shapes.end(); i++){
        (*i)->draw();
    }
    for(auto i = opponentCups.begin(); i != opponentCups.end(); i++){
        (*i)->draw();
    }
    for(auto i = playerCups.begin(); i != playerCups.end(); i++){
        (*i)->draw();
    }
    cursor->draw();
    ball->draw();
    
}

void MainScreen::keyDown(unsigned char key, float x, float y){

}

void MainScreen::leftMouseDown(float x, float y){
    ballIsFlying = false;
    if(havntShot && playerTurn) {
        ballDestination = 0;
        ball->setX(x); ball->setY(y);
        cursor->leftMouseDown(x, y);
    }
}

void MainScreen::leftMouseUp(float x, float y){
    if(havntShot && playerTurn) {
        launchBall(cursor->getX(), cursor->getY(), cursor->getPowerBarH());
        havntShot = false;
    }
    cursor->leftMouseUp(x,y);
}

void MainScreen::moveMouse(float x, float y) {
    cursor->changePos(x, y);
}

void MainScreen::advance() {
    cursor->advance();
    DancingGuy->advance();
    ball->advance();
    if (!playerTurn) {
        opponent->advance();
        if(!ballFlying && opponent->shootingDone()) {
            //switchTurns();
            computerLaunch();
        }
    }
    // if the ball has reached its destination
    if (ball->reachedDestination() && ballFlying) {
        ballFlying = false;

        if (hitCup(ball->getX(), ball->getY())) {
            havntShot=true;
            std::cout<<"Hit a cup!"<<std::endl;
        }
        else{
            switchTurns();
        }
    }
}

void MainScreen::computerLaunch() {
    float xDestination = RandomFloat(-0.15,0.1);
    float y = 0.7;
    float power = RandomFloat(0.18,0.25);
    ball->setX(xDestination);
    ball->setY(y);
    launchBall(xDestination, y, power);
}


float MainScreen::RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void MainScreen::launchBall(float x, float y, float power) {
    if(playerTurn){
        ball->playerLaunch(x,y,power);
    }
    else{
        ball->computerLaunch(x,y,power);   
    }
    ballFlying = true;
}

bool MainScreen::hitCup(float x, float y) {
    // loop through all cups
    int r = 0;
    if(playerTurn) {
        for(auto i = opponentCups.begin(); i != opponentCups.end(); i++){
            // check if x,y is on one of the cups
            if ((*i)->contains(x, y)) {
                opponentCups.erase(opponentCups.begin()+r);
                return true;
            }
            r++;
        }
    }
    else {
        for(auto i = playerCups.begin(); i != playerCups.end(); i++){
            // check if x,y is on one of the cups
            if ((*i)->contains(x, y)) {
                playerCups.erase(playerCups.begin()+r);
                opponent->shoot();
                return true;
            }
            r++;
        }
    }
}

void MainScreen::switchTurns() {
    playerTurn = !playerTurn;
    if(playerTurn==false){
        opponent->shoot();
    }
    if(playerTurn==true){
        havntShot = true;
    }
    //std::cout<<"Switching turns"<<std::endl;
}

bool MainScreen::noPlayerCupsLeft() {
    return playerCups.empty();
}
bool MainScreen::noOpponentCupsLeft() {
    return opponentCups.empty();
}

bool MainScreen::shouldChangeToNextScreen() {
    if(noPlayerCupsLeft() || noOpponentCupsLeft()) {
        return true;
    }
    else{
        return false;
    }
}

Screen* MainScreen::nextScreen() {
    if(noPlayerCupsLeft()) {
        LosingScreen* losingScreen = new LosingScreen();
        std::cout<<"You lose :("<<std::endl;
        return losingScreen;
    }
    else{
        WinningScreen* winningScreen = new WinningScreen();
        std::cout<<"You Win! :D"<<std::endl;
        return winningScreen;
    }
}

MainScreen::~MainScreen(){   
    for(auto i = shapes.begin(); i != shapes.end(); i++){
        delete *i;
    }
    //std::cout << "Exiting..." << std::endl;
}
