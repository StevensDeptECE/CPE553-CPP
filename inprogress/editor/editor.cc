#include "editor.hh"
#include <cstdio>
#include <fstream>
using namespace std;

int setvbuf(FILE *stream, char *buffer, int mode, size_t size);

void editor::bind(uint32_t input_event, action a) {
	uint32_t aid = action_map.size();
	action_map.push_back(a);
	input_map[input_event] = aid;
}

constexpr uint32_t ctrl(uint32_t input) { return input-32; }
constexpr uint32_t alt(uint32_t input) { return 512 | input; }

editor::editor(int rows, int cols) : w(), action_map(1024), input_map(1024) {
	cursor = 0;
	page_size = 30;
  setvbuf(stdin, nullptr, _IONBF, 0); //set stdin unbuffered
	//	bind(HOME, &editor::gotostart);
	//	bind(END, &editor::gotostart);
	bind(ctrl('e'), &editor::endofline);
	bind(ctrl('a'), &editor::startofline);
	bind(ctrl('f'), &editor::forward);
	bind(ctrl('b'), &editor::backward);
	bind(ctrl('n'), &editor::nextline);
	bind(ctrl('p'), &editor::prevline);
	//	bind(DOWN), &editor::pagedown);
	//	bind(UP), &editor::pageup);
	bind(ctrl(' '), &editor::setmark);
	bind(ctrl('x'), &editor::cut);
	bind(ctrl('v'), &editor::paste);
	bind(ctrl('g'), &editor::abort);
	bind(ctrl('0'), &editor::compile);
	mainloop();
}

editor::~editor() {
}

void editor::load(const char filename[]) {
	ifstream f(filename);
	f.seekg (0, ios::end);
	size_t size = (size_t)f.tellg();
	text.resize(size);
	f.seekg (0, ios::beg);
	f.read (&text[0], size);
	cursor = 0;
}

void editor::save(const char filename[]) {
	ofstream f(filename);
	f << text;
}

void editor::gotopos(uint64_t pos) {
	this->cursor = pos;
}

bool editor::gotostart() {
	gotopos(0);
	return true;
}

bool editor::gotoend() {
	gotopos(text.length()-1);
	return true;
}

bool editor::startofline() {
  for (int32_t i = cursor; i >= 0; i--)
		if (text[i] == '\n') {
			cursor = i+1;
			return true;
		}
	cursor = 0;
	return true;
}

bool editor::endofline() {
	return true;
}

bool editor::forward() {
	cursor++;
	if (cursor >= text.length())
		cursor = text.length()-1;
	return true;
}

bool editor::backward() {
	cursor--;
	if (cursor < 0)
		cursor = 0;
	return true;
}

bool editor::nextline() {
	return true;
}

bool editor::prevline() {
	return true;
}

bool editor::setmark(){
	return true;
}

bool editor::cut() {
	return true;
}

bool editor::paste() {
	return true;
}

bool editor::abort() {
	return true;
}

bool editor::compile() {
	return true;
}

bool editor::undo() {
	return true;
}

bool editor::redo() {
	return true;
}

bool editor::repeat() {
	return false;
}

bool editor::pageup() {
	uint32_t count = 0;
	for (uint32_t i = cursor; i >= 0; i--) {
		if (text[i] == '\n') {
			count++;
			if (count > page_size) {
				cursor = i;
				return true;
			}
		}
	}
	cursor = 0;
	return true;
}

bool editor::pagedown() {
	uint32_t count = 0;
	for (uint32_t i = cursor; i < text.length(); i++) {
		if (text[i] == '\n') {
			count++;
			if (count > page_size) {
				cursor = i;
				return true;
			}
		}
	}
	cursor = text.length()-1;
	return true;
}

void editor::mainloop() {
	w.clear();
	display();
	int c;
	while (c = getc(stdin)) {
		uint32_t action = input_map[c];
		if ((this->*action_map[action])())
			display();
	}
	w.clear();
	cout << "editor done\n";
}

void editor::display() {
	w.gotorc(0,0);
	w.flush();
	const uint32_t rows = 32; // current size of screen
	uint32_t r = 0;
	for (uint64_t i = cursor; i < text.length(); i++) {
		if (text[i] == '\n') {
			r++;
			if (r >= page_size) {
				//				w.print(&text[cursor], i - cursor+1);
				return;
			}
		}
	}
}
