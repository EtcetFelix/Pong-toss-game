#include "LosingScreen.h"

LosingScreen::LosingScreen() : Screen(){
    //background
    background = new TexRect("losingImage.png", -1, 1, 2, 2);

}

void LosingScreen::draw() const{
    background->draw();
}

LosingScreen::~LosingScreen() {
    delete background;
}