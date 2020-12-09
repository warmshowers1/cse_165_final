#include "Minion.h"
#include <iostream>

Minion::Minion(float x=0, float y=-0.9, float w=0.1, float h=0.1): Alien("images/alien2.png", x, y, w, h){
    lives = 1;
}
