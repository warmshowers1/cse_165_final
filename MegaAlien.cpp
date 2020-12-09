#include "MegaAlien.h"
#include <iostream>

MegaAlien::MegaAlien(float x=0, float y=-0.9, float w=0.1, float h=0.1): Alien("images/alien1.png", x, y, w, h){
    lives = 2;
}
