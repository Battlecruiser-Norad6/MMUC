#include "game_master.h"
#include "Dungeon.h"
#include <iostream>

using namespace std;



//constructors
game_master::game_master() {
	//default constructor
	cout << "New game obj created...\n";
	cout << "Board initialized to all 0s...\n";
	main_board.set0();
	main_board.display();
	Position startpos(Hero_startx, Hero_starty);
	main_hero = Hero(startpos);
}
game_master::game_master(char *filename) {
	//constructor with custom file input - Jason
	cout << "CustomFile game created...\n";
	if (main_board.readfromFile(filename)==1) {
		cout << "Board initialized to all 0s...\n";
		main_board.set0();
	}
	boardsetup();

}
void game_master::prompt() {
	//prompts the user for input, updates hero -Jason
	char cmd;
	d2.debugpos(debug_mode, "main_hero",main_hero.getPos());
	cout << "Enter command :";
	cin >> cmd;
	switch (cmd) {
	case 'w':case 'W':
		d2.debugprint(debug_mode, "moveup()");
		main_hero.moveUp();
		break;
	case 'a':case'A':
		d2.debugprint(debug_mode, "moveleft()");
		main_hero.moveLeft();
		break;
	case 's':case'S':
		d2.debugprint(debug_mode, "movedown()");
		main_hero.moveDown();
		break;
	case 'd':case'D':
		d2.debugprint(debug_mode, "moveright()");
		main_hero.moveRight();
		break;
	default:
		cout << "Please enter a valid command!\n";
		break;
	}
}
int game_master::instance() {
	//to be looped -Jason
	//display the board first
	main_board.display();

	//prompt for action
	prompt();
	//update based on action
	return main_board.setHeroPos(main_hero);
}


void game_master::boardsetup() {
	//function to read board info from dungeon class
	//updates the entities in the game with their respective position.
	//NOTE, empty spaces and walls are NOT considered an entity here.
	//as of 1/6/2018, only able to read HERO entity -Jason
	boardsizeX = main_board.getBoardX();
	boardsizeY = main_board.getBoardY();
	int i, j;
	Position tmppos;
	for (i = 0; i < boardsizeX; i++) {
		for (j = 0; j < boardsizeY; j++) {
			switch (main_board.getPosInfo(i, j)) {
			case entities::e_hero:
				d2.debugprint(debug_mode, "Hero entity found on board...initializing");
				tmppos.setX(i);
				tmppos.setY(j);
				main_hero = Hero(tmppos);
				d2.debugpos(debug_mode, "Hero", tmppos);
				break;
			case entities::e_victory:
				d2.debugprint(debug_mode, "Victory point found on board...initializing");
				tmppos.setX(i);
				tmppos.setY(j);
				main_board.setVicPos(tmppos);
				d2.debugpos(debug_mode, "Victory point", tmppos);
				break;
			default:
				//default case
				break;
			}
		}
	}
}

