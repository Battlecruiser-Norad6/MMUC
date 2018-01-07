/*this will be the main object for the dungeon assignment program*/
/*this project was made for MMU c++ assignment requirement       */

#include "stdafx.h"
#include "Hero.h"
#include "Position.h"
#include "game_master.h"
#define testinstance 50 //sample number. maximum number of moves

int main()
{
	int count;
	game_master newgame("MAP01.txt");
	for (count = 0; count < testinstance; count++) {
		if (newgame.instance() == board_update_state::victory_pos) {
			//if the instance returns the hero to be in a victory position
			//end the game -Jason
			cout << "VICTORY!!!! TENNOHEIKA BANZAI!!" << endl << endl;
			break;
		}
	}
    return 0;
}

