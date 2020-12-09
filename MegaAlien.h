#ifndef MegaAlien_h
#define MegaAlien_h

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


class MegaAlien: public Alien{

public:
    MegaAlien(float, float, float, float);
};

#endif
