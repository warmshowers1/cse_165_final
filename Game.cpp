#include "Game.h"
#include "Rect.h"
#include "TexRect.h"
#include<iostream>
#include<fstream>
#include<math.h>
#include<deque>
#include<time.h>
#include<stdlib.h>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

using namespace std;

Game::Game(float width){
    text = new Text(width);
    ship = new TexShip(0, -0.75, 0.1, 0.1);
    background = new TexRect("images/background.jpg", -1, 1, 2, 2);
    for(int i = 0; i < 2; i++){ // Always starts with 2 lives
        lives.push_back(new TexRect("images/ship.png", 
            (-0.98 + (0.09 * i)), -0.9, 0.08, 0.08));
    }

    seed = time(NULL);
    score = 0;
}

void Game::draw(){
    background->draw();
    ship->draw();
    for(auto it = lives.cbegin(); it != lives.cend(); ++it)
        (*it)->draw();
}

void Game::moveShip(int much){ 
    
}

Game::~Game(){
    delete text;
    delete ship;
    delete background;
    // Add delete for aliens deque
}
