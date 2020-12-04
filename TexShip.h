#ifndef TexShip_h
#define TexShip_h

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


class TexShip: public TexRect{

public:
    TexShip(float, float, float, float);
    
    void draw(float z=0) const;
    bool contains(float, float) const;
};

#endif
