//self defines headers
#include "Dungeon.h"
#include "Position.h"
#include "Hero.h"
#include "game_master.h"
//std libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//constructors
Dungeon::Dungeon() {
	//default constructor
}

//modifers
void Dungeon::set0() {
	//set the board to all empty spaces
	int i, j;
	for (i = 0; i < BOARDSIZEX; i++) {
		for (j = 0; j < BOARDSIZEY; j++) {
			board[i][j] = entities::e_empty;
		}
	}
	pureDisplay();
}

void Dungeon::pureDisplay() {
	int i, j;
	for (i = 0; i < BOARDSIZEX; i++) {
		cout << "  ";
		for (j = 0; j < BOARDSIZEY; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
}

//displayers
void Dungeon::display() {
	//a function to display the entities on the board
	int i, j;
	char disp;
	for (i = 0; i < BOARDSIZEX+2; i++) {
		//print two spaces to the right for better visibility
		cout << "  ";
		for (j = 0; j < BOARDSIZEY+2; j++) {
			if (i<1 || j<1 || i>BOARDSIZEX || j>BOARDSIZEY) {
				//borders
				if ((i == 0 && j == 0)||(i==BOARDSIZEX+1&&j==BOARDSIZEY+1)) {
					disp = '+';// alternatively '/'
				}
				else if ((i==0 && j== BOARDSIZEY+1)||(j==0 && i==BOARDSIZEX+1)) {
					disp = '+';// alternatively '\'
				}
				else if (j==0||j==BOARDSIZEY+1)
				{
					disp = '|';
				}
				else {
					disp = '-';
				}
			}else{
				//print the board
				switch (board[i-1][j-1]) {
				case entities::e_empty:
					//prints empty spaces for 0 (nothing)
					if (debug_mode) disp = debugging::deb_disp_empty;
					else disp = disp_graphics::d_empty;
					break;
				case entities::e_hero:
					if (debug_mode) disp = debugging::deb_disp_hero;
					disp = disp_graphics::d_hero;
					break;
				case entities::e_wall:
					disp = disp_graphics::d_wall;
					break;
				case entities::e_victory:
					disp = disp_graphics::d_vicpoint;
					break;
				default:
					//prints a 0 on screen for error locations
					d1.debugprint(debug_mode, "Found some error at following loc:");
					cout << i << "," << j << endl;
					disp = disp_graphics::d_error;
				}
			}
			//print it
			cout << disp;
		}
		cout << endl;
	}
}

//entity_changer
int Dungeon::setHeroPos(Hero &hero) {
	//sets the hero position. returns 0 upon success -Jason
	d1.debugprint(debug_mode, "attempting to update hero position...");
	if (isValid(hero.getPos())){
		//
		d1.debugprint(debug_mode, "new hero position is valid,new position registered");
		board[hero.getPrevPos().getX()][hero.getPrevPos().getY()] = entities::e_empty;
		board[hero.getPos().getX()][hero.getPos().getY()] = entities::e_hero;
		if (hero.getPos() == vicpos) {
			return board_update_state::victory_pos;
		}
		else {
			return board_update_state::success;
		}
		
	}
	else {
		d1.debugpos(debug_mode, "attempted pos:", hero.getPos());
		hero.setPos(hero.getPrevPos());//this has to be set as the hero's position is changed
		//at the prompt in game_master
		d1.debugpos(debug_mode, "retained pos:", hero.getPos());
		d1.debugprint(debug_mode, "new hero position is invalid,old position retained");
		return board_update_state::invalid_pos;
	}
}

bool Dungeon::isValid(Position heropos) {
	//checks if the position is a valid position -Jason
	int posState = board[heropos.getX()][heropos.getY()];

	//attention!!
	//this has to be changed if we want the hero to move into monsters and items
	if (posState != entities::e_empty) {
		//return false if heropos is not empty, not it is the hero.
		if (posState == entities::e_victory) {
			return true;
		}
		else {
			d1.debugprint(debug_mode, "False returned from isValid() check");
			return false;
		}
	}
	//done checking all types.
	d1.debugprint(debug_mode, "True returned from isValid() check");
	return true;
}

//FILE IO requried functions
int Dungeon::readfromFile(char *filename) {
	//function to readin a custom map. reads in 'filename'
	//rmb to include a .txt -Jason
	ifstream dungeon_file(filename);
	/* TESTING CODE */
	/* created 1/5/2018 1:19AM */
	//tested with positive results. now able to import text files as maps -Jason
	/*
	ofstream test_file("testout.txt");
	if (test_file.is_open()) {
		test_file << "testing123" << endl;
		test_file << "ting123" << endl;
		test_file << "time now is 1:17AM" << endl;
		test_file.close();
	}
	*/
	if (dungeon_file.is_open()) {
		int i, j;
		string inpline;
		i = 0;
		//first 2 numbers is metadata,x and y size
		while ( getline(dungeon_file, inpline)) {
			for (j = 0; j < size(inpline); j++) {
				board[i][j] = int(inpline[j])-48;//ascii '0' is 48
			}
			i++;
		}
		d1.debugprint(debug_mode, "Dungeon file read successfully...");
		if (debug_mode) pureDisplay();
		dungeon_file.close();
		return 0;//success
	}
	else {
		//error opening the file, return 1
		cout << "Error opening file:" << filename << endl;
		return 1;
	}
}
int Dungeon::getBoardX() {
	return (sizeof(board) / getBoardY())/sizeof(int);
}
int Dungeon::getBoardY() {
	return sizeof(board[0])/sizeof(int);
}
int Dungeon::getPosInfo(int x, int y) {
	return board[x][y];
}
void Dungeon::setVicPos(Position target) {
	vicpos = target;
}
