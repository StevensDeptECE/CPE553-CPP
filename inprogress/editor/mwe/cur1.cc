#include <iostream>
#include <unistd.h>
using namespace std;

#define CSI "\033["
class TextWin {
private:
  ostream& s;
public:
	TextWin(ostream& s) : s(s) { clear(); }
	void clear() {
		s << CSI "2J";
	}
	void gotorc(int row, int col) {
		s << CSI << row << ';' << col << 'H';
	}
	void nomods() {
		s << CSI "0m";
	}
	void setFG(uint32_t rgb) {
		s << CSI "38;2;"
			<< ((rgb >> 16) & 0xFF) << ';'
			<< ((rgb >> 8) & 0xFF) << ';'
			<< (rgb & 0xFF) << "m";
	}
	void setBG(uint32_t rgb) {
		s << CSI << "48;2;"
			<< ((rgb >> 16) & 0xFF) << ';'
			<< ((rgb >> 8) & 0xFF) << ';'
			<< (rgb & 0xFF) << "m";
	}
	void print(const char str[]) {
		s << str;
	}
	void print(int v) {
		s << v;
	}
	void underline() {
		s << CSI "4m";
	}
	void bold() {
		s << CSI "1m";
	}
	void print(int row, int col, uint32_t val) {
		gotorc(row,col);
		s << val;
	}
	void flush() {
		s << std::flush;
	}
};

int main() {
	TextWin w(cout);
	w.setFG(0x0040FF);
	for (int i = 0; i < 10; i++) {
		w.gotorc(10+i,3);
		w.print("test");
	}
	w.bold();
	w.print(2, 30, 42);
  w.flush();
	sleep(5);

}
