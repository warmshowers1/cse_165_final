#ifndef Minion_h
#define Minion_h

#include "Alien.h"

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


class Minion: public Alien{

public:
    Minion(float, float, float, float);
};

#endif
