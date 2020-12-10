#include "Minion.h"
#include <iostream>

Minion::Minion(float x, float y, float w, float h): Alien("images/alien2.png", x, y, w, h){
    lives = 1;
}
