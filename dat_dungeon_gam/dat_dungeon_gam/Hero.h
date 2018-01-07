#ifndef HERO_H
#define HERO_H
#include "Position.h"

class Hero {
private:
	Position currPos;			//current position of Hero, object of Position class
	Position prevPos;
public:
	//constructors
	Hero(Position);
	Hero();
	//member functions
	//movements
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	//get pos
	Position getPos();
	Position getPrevPos();
	//set pos
	void setPos(Position);
};
#endif
