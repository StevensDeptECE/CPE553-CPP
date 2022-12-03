#include <iostream>
#include <unistd.h>
using namespace std;

#define CSI "\033["
class TextWin {
private:
  ostream& s;
public:
	TextWin(ostream& s) : s(s) {}
	void clear();
	void gotorc(int row, int col);
	void nomods() {
		s << CSI << "0m";
	}
	void setLowColor(uint8_t fg, uint8_t bg) {
		if (fg >= 8 || bg >= 8)
			return;
		s << CSI << (30 + fg) << ';' << (40 + bg) << 'm';
	}
	void setFG(uint32_t rgb);
	void setBG(uint32_t rgb);
	void setColor(uint32_t fgrgb, uint32_t bgrgb);
	void up();
	void down();
	void left();
	void right();
	void nextline();
	friend TextWin& operator <<(TextWin& s, const char str[]) {
		s.s << str;
		return s;
	}
	friend TextWin& operator <<(TextWin& s, int v) {
		s.s << v;
		return s;
	}
	void underline() {
		s << CSI << "4m";
	}
	void blink() {
		s << CSI << "5m";
	}
	void bold() {
		s << CSI << "1m";
	}
	
	void strikethrough() {
		s << CSI << "9m";
	}
	char hexDigit(int d) {
		return d >= 10 ? ('A'-10) + d : d + '0';
	}
	void printHex(int row, int col, uint32_t val) {
		gotorc(row,col);
		s
			<< hexDigit(val >> 28)
			<< hexDigit((val >> 24) & 0xF)
			<< hexDigit((val >> 20) & 0xF)
			<< hexDigit((val >> 16) & 0xF)
			<< hexDigit((val >> 12) & 0xF)
			<< hexDigit((val >> 8) & 0xF)
			<< hexDigit((val >> 4) & 0xF)
			<< hexDigit(val & 0xF);
	}
	void print(int row, int col, uint32_t val) {
		gotorc(row,col);
		s << val;
	}
	void print(int row, int col, uint64_t val) {
		gotorc(row,col);
		s << val;
	}
	void flush() {
		s << std::flush;
	}
};

void TextWin::setFG(uint32_t rgb) {
	s << CSI << "38;2;"
		<< ((rgb >> 16) & 0xFF) << ';'
		<< ((rgb >> 8) & 0xFF) << ';'
		<< (rgb & 0xFF) << "m";
}

void TextWin::setBG(uint32_t rgb) {
	s << CSI << "48;2;"
		<< ((rgb >> 16) & 0xFF) << ';'
		<< ((rgb >> 8) & 0xFF) << ';'
		<< (rgb & 0xFF) << "m";
}

void TextWin::setColor(uint32_t fgrgb, uint32_t bgrgb) {
	setFG(fgrgb);
	setBG(bgrgb);
}


void TextWin::clear() {
	s << CSI << "2J";
}

void TextWin::gotorc(int row, int col) {
	s << CSI << row << ';' << col << 'H';
}

void TextWin::up() {
	s << CSI "A";
}
void TextWin::down() {
	s << CSI "B";
}
void TextWin::left() {
	s << CSI "D";
}
void TextWin::right() {
	s << CSI "C";
}

void TextWin::nextline() {
  s << CSI "E";
}
int main() {
	TextWin t(cout);
	t.setBG(0x001040);
	t.clear();
	for (int i = 0; i < 10; i++) {
		t.setLowColor(i, 0);
		t.gotorc(10+i,3);
		t << "test" << i;
	}
	t.gotorc(6,30);
	t.setFG(0xFF0000);
	t.strikethrough();
	t << "test";
	t.gotorc(8,30);
	t.setFG(0x00FF00);
	t.underline();
	t << "test";
	t.gotorc(10,30);
	t.nomods();
	t.setFG(0x0000FF);
	t << "test";

 
	const char* regnames[] = {
		"r0", "r1", "r2", "r3", "r4", "r5","r6", "r7",
		"r8", "r9", "r10", "r11", "r12", "lr","sp", "pc"
	};
	for (int i = 0; i < sizeof(regnames) / sizeof(char*); i++) {
		t.gotorc(1+i, 50);
		//		t.setLowColor(1, i);
		t.setColor(0x00FF00, 0x000000);
		t << regnames[i];
		if (i > 5)
			t.setColor(0xFFFFFF, 0x000060);
    if (i < 7)
			t.blink();
		t.printHex(1+i, 54, 0xA0203f34);
	}

	for (int i = 0; i < 100; i++) {
		time_t now = time(nullptr);
		t.print(25, 0, uint64_t(now));
		t.flush();
		sleep(1);
	}
	
}
	
