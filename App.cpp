#include <iostream>
#include "App.h"

using namespace std;

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){

    // Pushing different kinds of Shape in the collection
    game = new Game(width);
} 

void App::draw() const {
    game->draw();
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    if(key == 'a'){
        game->moveShip(true);
    }
    if(key == 'd'){
        game->moveShip(false);
    }
}

void App::leftMouseDown(float x, float y){
    if(game->shipHit(x, y))
        cout << "Ship hit" << endl;
}

void App::idle(){
    redraw();
}

App::~App(){   
    std::cout << "Exiting..." << std::endl;
    delete game;
}
