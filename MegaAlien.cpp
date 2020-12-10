#include "MegaAlien.h"
#include <iostream>

MegaAlien::MegaAlien(float x, float y, float w, float h): Alien("images/alien1.png", x, y, w, h){
    lives = 2;
}
