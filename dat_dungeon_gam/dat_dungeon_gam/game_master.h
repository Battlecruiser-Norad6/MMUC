#ifndef GAME_MASTER_H
#define GAME_MASTER_H
#include "Hero.h"
#include "Position.h"
#include "Dungeon.h"
#include "debugger.h"
#define debug_mode true

#define Hero_startx 1
#define Hero_starty 1

class game_master {
private:
	Hero main_hero;
	Dungeon main_board;
	debugger d2;
	int boardsizeX;
	int boardsizeY;
public:
	//constructors
	game_master();
	game_master(char *);

	//runnable
	void prompt();
	int instance();

	//board setup
	void boardsetup();
};

#endif


