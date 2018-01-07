#include "Hero.h"
#include "Position.h"
#include "stdafx.h"
//movements definitions
//created -Suilyn
//edit:1/5/2018 changed the values to fit the array -Jason
void Hero::moveRight() {
	prevPos = currPos;
	currPos.setY(currPos.getY() + 1);
}
void Hero::moveLeft() {
	prevPos = currPos;
	currPos.setY(currPos.getY() - 1);
}
void Hero::moveUp() {
	prevPos = currPos;
	currPos.setX(currPos.getX() - 1);
}
void Hero::moveDown() {
	prevPos = currPos;
	currPos.setX(currPos.getX() + 1);
}

//set pos
void Hero::setPos(Position target) {
	currPos = target;
}

//retrieval definitions
Position Hero::getPos() {
	return currPos;
}
Position Hero::getPrevPos() {
	return prevPos;
}

//constructors
Hero::Hero(Position defaultpos) {
	currPos = defaultpos;
}
Hero::Hero() {
	//default
}


