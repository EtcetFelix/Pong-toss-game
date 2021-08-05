#include "WinningScreen.h"

WinningScreen::WinningScreen() : Screen(){
    //background
    background = new TexRect("WinImage.png", -1, 1, 2, 2);

}

void WinningScreen::draw() const{
    background->draw();
}

WinningScreen::~WinningScreen() {
    delete background;
}