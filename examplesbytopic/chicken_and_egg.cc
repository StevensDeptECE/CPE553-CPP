/* 
It is impossible to have two objects contain each other
This would be infinitely recursive and infinite space

class A {
private:
	B b1;
};

class B {
private:
	A a1;
};
*/


/*
It is possible to have one object contain others, and the others contain a pointer to the first.
In this case, we have both contain pointers to each other
*/

class Board; // declaration

class Piece {
private:
	uint16_t pos;
	Board* containedBy;
public:
	void move(int x, int y );

};

class Board {
	std::vector<Piece*> pieces;
public:

};


void Piece::move(int x, int y ) {
	int calculateNew = x*w+y;
	board->move(this, calculateNew);
}
