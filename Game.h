#ifndef GAME_H
#define GAME_H
// #include "Shape.h"
#include "Text.h"
#include "Ship.h"
#include "Alien.h"
#include "Minion.h"
#include "MegaAlien.h"
#include "Bullet.h"
#include <deque>
#include <time.h>


class Game {
    Text* text;
    Shape* background;
    Rect* ship;

    std::deque<Alien*> aliens;
    std::deque<Shape*> lives;
    std::deque<Rect*> bounds;
    std::deque<Bullet*> bullets;
    
    long seed;
    int score;

public:
	Game();
    Game(float);

	void draw();
    void moveShip(bool left) const ;
    bool noLives();

	~Game();

    void shoot();
    void check(float x, float y); // Still need it?
};




#endif
