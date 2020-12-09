#include "Bullet.h"
#include <iostream>

Bullet::Bullet(float x=0, float y=-0.9): TexRect("images/bullet.png", x, y, 0.025, 0.05){
    tX = x + (w/2);
    tY = y;
}

// Maybe do more
void Bullet::move(float amt){
    y += amt;
}
/*
bool Bullet::contains(float x, float y) const {
    return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}
*/
