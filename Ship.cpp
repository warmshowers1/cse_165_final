#include "Ship.h"
#include <iostream>

Ship::Ship(float x=0, float y=-0.9, float w=0.1, float h=0.1): TexRect("images/ship.png", x, y, w, h){}


void Ship::draw(float z) const {
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    
    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(0, 0);
    glVertex3f(x, y - h, z);
    
    glTexCoord2f(0, 1);
    glVertex3f(x, y, z);
    
    glTexCoord2f(1, 1);
    glVertex3f(x+w, y, z);
    
    glTexCoord2f(1, 0);
    glVertex3f(x+w, y - h, z);
    
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
}

bool Ship::contains(float x, float y) const {
    //            (sx[0],sy[0])
    //                  o
    //                 / \
    //                /   \
    //               /     \
    //              /       \
    //             o---------o
    //   (sx[1],sy[1])     (sx[2],sy[2])
    float sx[3] = {this->x + (w/2), this->x, this->x + w};
    float sy[3] = {this->y, this->y - h, this->y - h};
    float a = ((sy[1] - sy[2]) * (x - sx[2]) + (sx[2] - sx[1]) * (y - sy[2])) / ((sy[1] - sy[2]) * (sx[0] - sx[2]) + (sx[2] - sx[1]) * (sy[0] - sy[2]));
    float b = ((sy[2] - sy[0]) * (x - sx[2]) + (sx[0] - sx[2]) * (y - sy[2])) / ((sy[1] - sy[2]) * (sx[0] - sx[2]) + (sx[2] - sx[1]) * (sy[0] - sy[2]));
    float c = 1 - a - b;
    return (0 <= a && a <= 1) && (0 <= b && b <= 1) && (0 <= c && c <= 1);
}

void Ship::moveLeft(){
    if(this->x >= -1) // The left edge of the screen
        this->x -= 0.0025;
}

void Ship::moveRight(){
    if(this->x <= 1 - this->w) // The right edge of the screen
        this->x += 0.0025;
}
