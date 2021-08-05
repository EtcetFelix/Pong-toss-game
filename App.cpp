#include <iostream>
#include "App.h"

static App* singleton;

void timer(int id) {
    singleton->advance();
    singleton->redraw();

    glutTimerFunc(singleton->interval, timer, id);
}

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    game = new Game();
    interval = 125;
    singleton=this;
    timer(1);
} 

void App::draw() const {
    game->draw();
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    redraw();
}

void App::leftMouseDown(float x, float y){
    game->leftMouseDown(x,y);
    redraw();
}

void App::leftMouseUp(float x, float y){
    game->leftMouseUp(x,y);
    redraw();
}

void App::moveMouse(float x, float y) {
    game->moveMouse(x, y);
    redraw();
}

void App::advance() {
    game->advance();
}

App::~App(){   
    delete game;
    std::cout << "Exiting..." << std::endl;
}
