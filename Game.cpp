#include "Game.h"
// #include "Rect.h"
// #include "TexRect.h"
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
    ship = new Ship(0, -0.75, 0.1, 0.1);
    background = new TexRect("images/background.jpg", -1, 1, 2, 2);
    for(int i = 0; i < 2; i++){ // Always starts with 2 lives
        lives.push_back(new Ship((-0.98 + (0.09 * i)), 
            -0.9, 0.08, 0.08));
    }
    for(int i = 0; i < 2; i++){ // 2 rows of 
        for(int j = 0; j < 10; j++) // 10 minions
            aliens.push_back(new Minion(-0.9 + (j * 0.18), 
                0.25 + (i * 0.15), 0.1, 0.1));
    }
    for(int i = 0; i < 6; i++)
        aliens.push_back(new MegaAlien(-0.54 + (i * 0.18), 
                0.6, 0.1, 0.1));
    thing = new Bullet(0,0);

    seed = time(NULL);
    score = 0;
}

void Game::draw(){
    // Always have these render first!
    background->draw();
    ship->draw();

    text->renderText(-0.96, 0.9, "1UP");
    text->renderText(-0.25, 0.9, "HIGH SCORE");
    text->renderText(-0.96, 0.8, to_string(score), 1, 1, 1);
    for(auto it = lives.cbegin(); it != lives.cend(); ++it)
        (*it)->draw();
    for(auto it = aliens.cbegin(); it != aliens.cend(); ++it)
        (*it)->draw();

    thing->draw();
    thing->move(0.005);
}

void Game::moveShip(bool left) const { 
    if(left)
        ship->moveLeft();
    else
        ship->moveRight();
}

bool Game::shipHit(float x, float y){
    // Probably should add a ship death here
    return ship->contains(x,y);
}

Game::~Game(){
    delete text;
    delete background;
    delete ship;
    aliens.clear();
    lives.clear();
    // Add delete for aliens deque
}
