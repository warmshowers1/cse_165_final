#ifndef Minion_h
#define Minion_h

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


class Minion: public TexRect{

public:
    Minion(float, float, float, float);
    
    bool contains(float, float) const;
    void moveLeft();
    void moveRight();
};

#endif
