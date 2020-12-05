#include "Minion.h"
#include <iostream>

Minion::Minion(float x=0, float y=-0.9, float w=0.1, float h=0.1): TexRect("images/alien2.png", x, y, w, h){}


bool Minion::contains(float x, float y) const {
    return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}

void Minion::moveLeft(){
    if(this->x >= -1) // The left edge of the screen
        this->x -= 0.0025;
}

void Minion::moveRight(){
    if(this->x <= 1 - this->w) // The right edge of the screen
        this->x += 0.0025;
}
