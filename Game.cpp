#include <iostream>
#include "Game.h"

Game::Game(){
    currentScreen = new MainScreen();

}

void Game::draw() const {
    currentScreen->draw();

}

void Game::keyDown(unsigned char key, float x, float y){

}

void Game::leftMouseDown(float x, float y){ 
    currentScreen->leftMouseDown(x, y);
}

void Game::leftMouseUp(float x, float y){ 
    currentScreen->leftMouseUp(x, y);
}

void Game::moveMouse(float x, float y) {
    currentScreen->moveMouse(x, y);
    
}

void Game::advance() {
    currentScreen->advance();
    if(currentScreen->shouldChangeToNextScreen()) {
        currentScreen = currentScreen->nextScreen();
    }
}

void Game::idle() {

}