#include "Bullet.h"
#include <iostream>

Bullet::Bullet(float tX=0, float tY=-0.9): TexRect("images/bullet.png", x, y, 0.025, 0.05){
    this->tX = tX;
    this->tY = tY;
    x = tX - (w/2);
    y = tY;
}

float Bullet::gettX() const {
    return tX;
}

float Bullet::gettY() const {
    return tY;
}

// Maybe do more
void Bullet::move(){
    y += 0.005;
}
/*
bool Bullet::contains(float x, float y) const {
    return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}
*/
