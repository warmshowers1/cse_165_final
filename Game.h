#ifndef GAME_H
#define GAME_H
#include "Shape.h"
#include "Text.h"
#include "Ship.h"
#include <deque>
#include <time.h>


class Game {
    Text* text;
    Text* scoreDisp;
    Shape* background;
    Ship* ship;

    std::deque<Shape*> aliens;
    std::deque<Shape*> lives;
    
    long seed;
    int score;

public:
	Game();
    Game(float);

	void draw();
    void moveShip(bool left) const ;
    bool shipHit(float x, float y);

	~Game();

    void shoot();
    void check(float x, float y); // Still need it?
};




#endif
