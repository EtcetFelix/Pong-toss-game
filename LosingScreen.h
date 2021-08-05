#ifndef LosingScreen_h
#define LosingScreen_h

#include <vector>
#include "Screen.h"
#include "TexRect.h"
#include "Sprite.h"

class LosingScreen: public Screen{
    TexRect* background;

public:
    
    LosingScreen();

    void draw() const;
    
    ~LosingScreen();
};

#endif
