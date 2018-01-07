#pragma once
#ifndef DUNGEON_H

#include "Position.h"
#include "debugger.h"
#include "Hero.h"
#define BOARDSIZEX 10
#define BOARDSIZEY 10

//enums to help with the graphics
enum entities {
	e_empty=0,e_hero=1,e_wall=2,e_victory
};
enum disp_graphics {
	d_error='0',d_empty=' ',d_hero='H',d_wall='*',d_vicpoint='t'
};
enum board_update_state {
	success,invalid_pos,victory_pos
};
enum debugging {
	deb_disp_empty = ' ', deb_disp_hero = 'H'
};

class Dungeon {
private:
	int board[BOARDSIZEX][BOARDSIZEY];
	debugger d1;
	Position vicpos;
public:
	//constructors
	Dungeon();
	//initializer
	void set0();
	void display();
	void pureDisplay();

	bool isValid(Position);

	//setters
	int setHeroPos(Hero &);
	void setVicPos(Position);

	//file IO
	int readfromFile(char *);

	//getboardsizes
	int getBoardX();
	int getBoardY();

	//getboard
	int getPosInfo(int, int);
};
#endif