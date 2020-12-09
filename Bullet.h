#ifndef Bullet_h
#define Bullet_h

#include "TexRect.h"

#if defined WIN32
#include <freeglut.h>
#include "../windows/SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include "SOIL.h"
#else
#include <GL/freeglut.h>
#include "SOIL.h"
#endif


class Bullet: public TexRect {
protected:
    // Tip of the bullet
    float tX;
    float tY;

public:
    Bullet(float x, float y);

    float gettX() const ;
    float gettY() const ;
    virtual void move();
};

#endif
