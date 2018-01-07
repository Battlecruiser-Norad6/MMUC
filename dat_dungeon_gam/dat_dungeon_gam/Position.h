#ifndef POSITION_H
#define POSITION_H
class Position {
private:
	int x;
	int y;
public:
	//constructors
	Position();
	Position(int, int);
	//member functions
	//gets
	int getX();
	int getY();
	//sets
	void setX(int hori);
	void setY(int vert);

	//overidden operators
	bool operator==(const Position &);
	void operator=(const Position &);
};
#endif