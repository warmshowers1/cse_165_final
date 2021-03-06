#include <iostream>
#include "App.h"

using namespace std;

bool playerLeft = false;
bool playerRight = false;

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
        playerLeft = true;
    }
    else if(key == 'd'){
        playerRight = true;
    }

    if(key == ' '){
        game->shoot();
    }
}

void App::specialKeyDown(int key, float x, float y){
    if(key == 100){
        playerLeft = true;
    }
    else if(key == 102){
        playerRight = true;
    }
}

void App::keyUp(unsigned char key, float x, float y){
    playerLeft = false;
    playerRight = false;
}

void App::specialKeyUp(int key, float x, float y){
    playerLeft = false;
    playerRight = false;
}

void App::idle(){
    if(playerLeft)
        game->moveShip(true);
    if(playerRight)
        game->moveShip(false);
    redraw();
    if( !(game->Won()) )
        game->check();
}

App::~App(){   
    std::cout << "Exiting..." << std::endl;
    delete game;
}
