#include "Game.h"
// #include "Rect.h"
// #include "TexRect.h"
#include<iostream>
#include<fstream>
#include<math.h>
#include<deque>
#include<ctime>
#include<stdlib.h>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

using namespace std;

bool dirMove = false;
const float LOWEST_ALIEN = 0.25;
time_t shotAt = NULL;

Game::Game(float width){
    text = new Text(width);
    ship = new Ship(0, -0.75, 0.1, 0.1);
    background = new TexRect("images/background.jpg", -1, 1, 2, 2);
    for(int i = 0; i < 2; i++){ // Always starts with 2 lives
        lives.push_back(new Ship((-0.98 + (0.09 * i)), 
            -0.9, 0.08, 0.08));
    }
    for(int i = 0; i < 2; i++){ // 2 rows of 
        for(int j = 0; j < 10; j++){ // 10 minions
            aliens.push_back(new Minion(-0.9 + (j * 0.18), 
                LOWEST_ALIEN + (i * 0.15), 0.1, 0.1));
            if(i == 0 && j == 0)
                bounds.push_back(new Rect(-0.9 + (j * 0.18), 0.8, 0.1, 0.1, 1, 1, 1));
            else if(i == 1 && j == 9)
                bounds.push_back(new Rect(-0.9 + (j * 0.18), 0.8, 0.1, 0.1, 1, 1, 1));
        }
    }
    for(int i = 0; i < 6; i++)
        aliens.push_back(new MegaAlien(-0.54 + (i * 0.18), 
                0.6, 0.1, 0.1));

    seed = time(NULL);
    score = 0;
    gameOver = false;
}

void Game::draw(){
    // Always have these render first!
    background->draw();

    if(!gameOver){
        ship->draw();

        text->renderText(-0.96, 0.9, "1UP");
        text->renderText(-0.25, 0.9, "HIGH SCORE");
        text->renderText(-0.96, 0.8, to_string(score), 1, 1, 1);

        // Draw in num lives
        for(auto it = lives.cbegin(); it != lives.cend(); ++it)
            (*it)->draw();

        // Draws bounds for testing
        for(auto it = bounds.cbegin(); it != bounds.cend(); ++it){
            // (*it)->draw(); // Comment out when done testing
            if(dirMove)
                (*it)->moveRight();
            else
                (*it)->moveLeft();
        }

        // Draws bullets and keeps them moving
        for(auto it = bullets.cbegin(); it != bullets.cend(); ++it){
            (*it)->draw();
            (*it)->move();
        }

        // Draws in aliens and switches 
        // travel direction if need be
        for(auto it = aliens.cbegin(); it != aliens.cend(); ++it){
            (*it)->draw();
            if(dirMove)
                (*it)->moveRight();
            else
                (*it)->moveLeft();
        }

        // Determine which directions aliens need to travel
        if(bounds.front()->getX() <= -1)
            dirMove = true;
        if( (bounds.back()->getX() + aliens.back()->getW()) >= 1)
            dirMove = false;
    }
    else{
        text->renderText(-0.3, 0.1, "-Results-");
        /*
        text->renderText(-0.3, 0, "-Results-");
        text->renderText(-0.3, -0.1, "-Results-");
        text->renderText(-0.3, -0.2, "-Results-");
        */
    }
}

void Game::moveShip(bool left) const { 
    if(left)
        ship->moveLeft();
    else
        ship->moveRight();
}

bool Game::noLives(){
    // Probably should add a ship death here
    return lives.empty();
}

bool Game::Won(){
    if(aliens.size() == 0){
        gameOver = true;
        return true;
    }
    return false;
}

void Game::shoot(){
    if(time(NULL) - shotAt >= 1 || shotAt == NULL){
        bullets.push_back(new Bullet(ship->getX() + (ship->getW()/2), ship->getY()));
        shotAt = time(NULL);
    }
}

void Game::check(){
    if(bullets.size() > 0){
        // Erases bullets that are out of bounds
        for(auto jt = bullets.begin(); jt != bullets.end();){
            if(!( (*jt)->inBounds() )){
                jt = bullets.erase(jt);
            }
            else{
                ++jt;
            }
        }
        bullets.shrink_to_fit();

        if(aliens.size() > 0){
            // Checks all aliens to see if a bullet hit
            // then erases both the alien and the bullet
            for(auto it = aliens.begin(); it != aliens.end(); it++){
                for(auto jt = bullets.begin(); jt != bullets.end();){
                    if((*jt)->gettY() >= (LOWEST_ALIEN - (*it)->getH())){
                        if((*it)->contains((*jt)->gettX(), (*jt)->gettY())){
                            cout << "HIT!" << endl;
                            if(it != aliens.end()-1){
                                it = aliens.erase(it);
                                jt = bullets.erase(jt);
                            }
                            else{
                                aliens.erase(it);
                                bullets.erase(jt);
                            }
                            score += 50;
                            break;
                        }
                        else{
                            ++jt;
                        }
                    }
                    else{
                        ++jt;
                    }
                }
            }
            aliens.shrink_to_fit();
            bullets.shrink_to_fit();
        }
        else{
            
        }
    }
}

Game::~Game(){
    delete text;
    delete background;
    delete ship;
    aliens.clear();
    lives.clear();
    bullets.clear();
    // Add delete for aliens deque
}
