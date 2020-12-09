#include "Alien.h"
#include <iostream>

Alien::Alien(const char* filename, float x=0, float y=-0.9, float w=0.1, float h=0.1): TexRect(filename, x, y, w, h){}

bool Alien::contains(float x, float y) const {
    return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}

void Alien::moveLeft(){
    if(this->x >= -1) // The left edge of the screen
        this->x -= 0.0025;
}

void Alien::moveRight(){
    if(this->x <= 1 - this->w) // The right edge of the screen
        this->x += 0.0025;
}
