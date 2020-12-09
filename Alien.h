#ifndef Alien_h
#define Alien_h

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


class Alien: public TexRect{
protected: 
    short int lives;

public:

    Alien(const char*, float, float, float, float);
    
    virtual bool contains(float, float) const;
    // void moveLeft();
    // void moveRight();
};

#endif
