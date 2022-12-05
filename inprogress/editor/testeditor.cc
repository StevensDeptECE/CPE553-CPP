#include "editor.hh"
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

editor::editor() {
	cursor = 0;
}

editor::~editor() {

}

void editor::open(const char filename[]) {
	ifstream f(filename);
	f.seekg (0, ios::end);
	size_t size = (size_t)f.tellg();
	text.resize(size);
	f.seekg (0, ios::beg);
	f.read (&text[0], size);
}

void editor::save(const char filename[]) {
	ofstream f(filename);
	f << text;
}


void editor::mainloop() {
	display();
	int c;
	while (c = getc(stdin)) {
		if (c == '\01') {
			//gotostartline();
		} else if (c == '\02') {

		} else if (c == '<') {
			gotostart();
			display();
		} else if (c == '>') {
			gotoend();
			display();
		}	else if (c=='\04') {
			return;
		} else if (c == '\05') {
			// gotoendline();
		}
		
	}
}

void editor::display() {
	uint64_t i = cursor;
	const uint32_t rows = 32; // current size of screen
	for (uint32_t j = 0; j < rows; j++) {
		for (;  i < text.length() && text[i] != '\n'; i++)
			cout << text[i];
		if (i >= text.length()) {
			cout << flush;
			return;
		}
		cout << '\n';
	}
	cout << flush;
}

void editor::gotopos(uint64_t pos) {
	cursor = pos;
}

int main() {
	editor e;
	e.open("test.txt");
	e.mainloop();
}
