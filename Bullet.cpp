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
    tY += 0.005;
}

bool Bullet::inBounds() const {
    return (this->x >= -1) && (this->x <= 1) && (this->y <= 1) && (this->y >= -1);
}

Bullet::~Bullet(){
    //Pretty sure this object is just data types, no objects
}
