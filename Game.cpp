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
    scoreDisp = new Text(width);
    ship = new Ship(0, -0.75, 0.1, 0.1);
    background = new TexRect("images/background.jpg", -1, 1, 2, 2);
    for(int i = 0; i < 2; i++){ // Always starts with 2 lives
        lives.push_back(new Ship((-0.98 + (0.09 * i)), 
            -0.9, 0.08, 0.08));
    }

    seed = time(NULL);
    score = 0;
}

void Game::draw(){
    // Always have these render first!!!
    background->draw();
    ship->draw();

    text->renderText(-0.96, 0.9, "1UP");
    text->renderText(-0.25, 0.9, "HIGH SCORE");
    scoreDisp->renderText(-0.96, 0.8, to_string(score));
    scoreDisp->setColor(1,1,1);
    for(auto it = lives.cbegin(); it != lives.cend(); ++it)
        (*it)->draw();
}

void Game::moveShip(bool left) const { 
    if(left)
        ship->moveLeft();
    else
        ship->moveRight();
}

bool Game::shipHit(float x, float y){
    if(ship->contains(x,y))
        return true;
    return false;
}

Game::~Game(){
    delete text;
    delete ship;
    delete background;
    // Add delete for aliens deque
}
