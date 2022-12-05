#include <iostream>
#include <unistd.h>

using namespace std;

class text_win {
private:
  static constexpr uint32_t bufsize = 4096;
  char buf[bufsize];
  uint32_t cursor; // current location in the buffer
	int screen;      // handle to stdout 
  #define CSIc '\033'    
  #define CSI "\033"
  void insert(char a) {
    buf[cursor++] = CSIc;
    buf[cursor++] = a;
  }
  void insert(char a, char b) {
    buf[cursor++] = CSIc;
    buf[cursor++] = a;
    buf[cursor++] = b;
  }
public:
	text_win() : cursor(0), screen(1) { clear(); }
	void clear() { insert('2', 'J'); }
	void gotorc(int row, int col) {
		int len = sprintf(buf + cursor, CSI "%d;%dH", row, col);
		cursor += len;
	}
	void setFG(uint8_t r, uint8_t g, uint8_t b) {
		int bytes = sprintf(buf + cursor, CSI "38;2;%d;%d;%dm",
												uint32_t(r), uint32_t(g), uint32_t(b));
		cursor += bytes;
	}
	void setBG(uint8_t r, uint8_t g, uint8_t b) {
		int bytes = sprintf(buf + cursor, CSI "38;2;%d;%d;%dm",
												uint32_t(r), uint32_t(g), uint32_t(b));
		cursor += bytes;
	}

	void nomods()    { insert('0', 'm'); }
	void bold()      { insert('1', 'm'); } 
	void underline() { insert('4', 'm'); }

	void print(uint32_t r, uint32_t c, const char str[]) {
		gotorc(r,c);
		for (int i = 0; str[i] != '\0'; i++)
			buf[cursor++] = str[i];
	}
	void print(uint32_t r, uint32_t c, uint32_t val) {
		gotorc(r,c);
		cursor += sprintf(buf+cursor, "%u", val);
	}
	void flush() {
		if (cursor >0) {
			write(screen, buf, cursor);
		}
	}
};

int main() {
  text_win w;	
	w.setFG(0x00,0x40,0xFF);
	for (int i = 0; i < 10; i++) {
		w.print(10+i,3,"test");
	}
	w.bold();
	w.print(2, 30, 42);
	w.flush();
	sleep(5);
}
