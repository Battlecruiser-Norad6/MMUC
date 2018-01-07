#ifndef DEBUGGER_H
#define DEBUGGER_H
#include <iostream>
#include "Position.h"
using namespace std;
class debugger {
public:
	void debugprint(bool debugging, char msg[]) {
		if (debugging) {
			cout << "Debugging mode: " << msg << endl;
		}
	}
	void debugpos(bool debugging, char ent[],Position printPos) {
		if (debugging) {
			cout << "Debugging mode: Position(" << ent << ") @ X,Y=" << printPos.getX() << "," << printPos.getY() << endl;
		}
	}
};
#endif