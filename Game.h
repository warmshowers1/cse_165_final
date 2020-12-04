#ifndef GAME_H
#define GAME_H
#include "Shape.h"
#include "Text.h"
#include "TexShip.h"
#include <deque>
#include <time.h>


class Game {
    Text* text;
    Shape* background;
    TexShip* ship;

    std::deque<Shape*> aliens;
    std::deque<Shape*> lives;
    
    long seed;
    int score;

public:
	Game();
    Game(float);

	void draw();
    void moveShip(int);

	~Game();

    void shoot();
    void check(float x, float y); // Still need it?
};




#endif
