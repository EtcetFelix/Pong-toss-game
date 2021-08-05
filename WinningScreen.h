#ifndef WinningScreen_h
#define WinningScreen_h

#include <vector>
#include "Screen.h"
#include "TexRect.h"
#include "Sprite.h"

class WinningScreen: public Screen{
    TexRect* background;

public:
    
    WinningScreen();

    void draw() const;
    
    ~WinningScreen();
};

#endif
