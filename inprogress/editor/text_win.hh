#pragma once

#include <iostream>
//#include <cstdlib>
#include <unistd.h>

using namespace std;

class text_win {
public:
  enum style {NOMODS = '0', BOLD = '1', ITALIC = '2', UL = '4', BLINK='5', STRIKE='9'};
private:
  static constexpr uint32_t bufsize = 32768;
  char buf[bufsize];
  uint32_t cursor; // current location in the buffer
  int screen; // handle to the screen
  #define CSI "\033"
  #define CSIc '\033'    
  void insert(char a) {
    buf[cursor++] = CSIc;
    buf[cursor++] = a;
  }
  void insert(char a, char b) {
    buf[cursor++] = CSIc;
    buf[cursor++] = a;
    buf[cursor++] = b;
  }
  void insert(char a, char b, char c) {
    buf[cursor++] = CSIc;
    buf[cursor++] = a;
    buf[cursor++] = b;
    buf[cursor++] = c;
  }
  void insert(char a, char b, char c, char d) {
    buf[cursor++] = CSIc;
    buf[cursor++] = a;
    buf[cursor++] = b;
    buf[cursor++] = c;
    buf[cursor++] = d;
  }
public:
	text_win();
	void clear() { insert('2', 'J'); }
	void gotorc(int row, int col) {
        int len = sprintf(buf + cursor, CSI "%d;%dH", row, col);
        cursor += len;
    }
	void setLowColor(uint8_t fg, uint8_t bg) {
        insert(30+fg, ';', 40+bg, 'm');
    }
	void setFG(uint32_t r, uint32_t g, uint32_t b) {
        int bytes = sprintf(buf + cursor, CSI "38;2;%d;%d;%dm",
		      r, g, b);
        cursor += bytes;
    }
	void setBG(uint32_t r, uint32_t g, uint32_t b) {
        int bytes = sprintf(buf + cursor, CSI "38;2;%d;%d;%dm",
		      r, g, b);
        cursor += bytes;
    }

	void setColor(uint32_t fg, uint32_t bg) {
      setBG(bg >> 16, (bg >> 8)&0xFF, bg & 0xFF);
      setFG(fg >> 16, (fg >> 8)&0xFF, fg & 0xFF);
    }

	void up()        { insert('A');   }
	void down()      { insert('B');   }
	void left()      { insert('D');   }
	void right()     { insert('C');    }
	void nextline()  { insert('E');    }
	void nomods()    { insert('0', 'm'); }
	void bold()      { insert('1', 'm'); } 
	void italics()   { insert('2', 'm'); } 
	void underline() { insert('4', 'm'); }
	void blink()     { insert('5', 'm'); }
	void strike()    { insert('9', 'm');	    }
	void super()     { insert('7', '3', 'm');	}
	void sub()       { insert('7', '4', 'm');	}

	friend text_win& operator <<(text_win& s, const char str[]) {
      for (int i = 0; str[i] != '\0'; i++)
        s.buf[s.cursor++] = str[i];
      return s;
	}
	friend text_win& operator <<(text_win& s, uint32_t val) {
      int len = sprintf(s.buf+s.cursor, "%u", val);
      s.cursor += len;
      return s;
	}
	char hexDigit(int d) {
		return d >= 10 ? ('A'-10) + d : d + '0';
	}
	void print(int row, int col,const char s[]) {
		gotorc(row, col);
		*this << s;
	}
	void print(int row, int col, const char s[], uint32_t len) {
		gotorc(row,col);
		*this << s;
	}
	void printHex(int row, int col, uint32_t val) {
        char buf[8] = {
          hexDigit(val >> 28),
		  hexDigit((val >> 24) & 0xF),
		  hexDigit((val >> 20) & 0xF),
		  hexDigit((val >> 16) & 0xF),
		  hexDigit((val >> 12) & 0xF),
		  hexDigit((val >> 8) & 0xF),
		  hexDigit((val >> 4) & 0xF),
		  hexDigit(val & 0xF)
        };
        print(row, col, buf, 8);
	}
	void print(int row, int col, uint32_t val) {
		gotorc(row,col);
		*this << val;
	}
	void print(int row, int col, uint64_t val) {
		gotorc(row,col);
		*this << val;
	}
	void print(int row, int col, int32_t val) {
		gotorc(row,col);
		*this << val;
	}
	void print(int row, int col, style s, uint8_t r, uint8_t g, uint8_t b, const char str[]) {
		gotorc(row,col);
        buf[cursor++] = s;
        setFG(r,g,b);
		*this << str;
	}
	void flush() {
        if (cursor >0) {
    		write(screen, buf, cursor);
            cursor = 0;
        }
	}
};
 	
