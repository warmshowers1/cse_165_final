#ifndef App_h
#define App_h

#include <vector>
#include "GlutApp.h"
#include "Rect.h"
#include "TexRect.h"
#include "Game.h"

class App: public GlutApp {

Game* game;

public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw() const;
    void keyDown(unsigned char key, float x, float y);
    void keyUp(unsigned char key, float x, float y);
    void specialKeyDown(int key, float x, float y);
    void specialKeyUp(int key, float x, float y);
    // void leftMouseDown(float x, float y);
    void idle();
    
    ~App();
};

#endif
