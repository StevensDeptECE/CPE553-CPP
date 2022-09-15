#include <iostream>
using namespace std;

class GameOfLife {
private:
	int* life;
	int* next;

	// it is easier (much) to apply the rules to one array, and store results in 2nd array than to do it all in one array

	//	next[i] = f(life)
	
	//copy each life[i] = next[i] and do it again

	// but it's faster to just do:

	//swap(life, next);
public:
	void computeNext(); // compute the next generation
	void print() const; // display the board
}


int main() {
	//https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
	// generate game of life specified in the data file
	GameOfLife g("gameoflife.dat");
}
