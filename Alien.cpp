#include "Alien.h"
#include <iostream>

Alien::Alien(const char* filename, float x, float y, float w, float h): TexRect(filename, x, y, w, h){}

bool Alien::contains(float x, float y) const {
    return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}
