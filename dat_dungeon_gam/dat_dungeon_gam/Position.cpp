#include "Position.h"
#include "stdafx.h"

//created -Suilyn
//get functions
int Position::getX() {
	return x;
}
int Position::getY() {
	return y;
}

//set functions
void Position::setX(int hori) {
	x = hori;
}
void Position::setY(int vert) {
	y = vert;
}

//constructors
Position::Position() {
	//default
}
Position::Position(int xi, int yi) {
	x = xi;
	y = yi;
}

//overidden
bool Position::operator==(const Position &src) {
	//overloaded operator == to return true if both positions are equal
	if (x == src.x&& y == src.y) {
		return true;
	}
	else {
		return false;
	}
}
void Position::operator=(const Position &src)
{
	x = src.x;
	y = src.y;
}
/*
Position & Position::operator=(const Position &src) {
	
}
*/