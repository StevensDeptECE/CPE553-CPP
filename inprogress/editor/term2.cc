#include <curses.h>
#include <iostream>
using namespace std;

int main() {
	int c;
	while (c = getch()) {
		cout << c << '\n';
	}
}
