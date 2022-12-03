#include "text_win.hh"
#include <unistd.h>
#include <fcntl.h>

text_win::text_win() : cursor(0) {
  screen = 1;
}

void test1() {
  text_win w;
  w.setBG(0x00,0x10,0x40);
  w.clear();
  w.print(0,0, 42);

  for (int i = 0; i < 10; i++) {
	w.setLowColor(i, 0);
	w.print(10+i,3, "test");
  }

  w.print(6,30, text_win::STRIKE, 0xFF,0x00,0x00, "test");
  w.print(8,30, text_win::UL, 0x00,0xFF,0x00, "test");
  w.print(10,30, text_win::NOMODS, 0x00,0x00,0xFF, "test");

    w.print(12,30, text_win::NOMODS, 0x00, 0xFF, 0xFF, "test");
    w.print(13,30, text_win::BOLD, 0x00, 0xFF, 0xFF, "test");
    w.print(14,30, text_win::ITALIC, 0x00, 0xFF, 0xFF, "test");
    w.print(15,30, text_win::UL, 0x00, 0xFF, 0xFF, "test");
    w.print(16,30, text_win::BLINK, 0x00, 0xFF, 0xFF, "test");

	const char* regnames[] = {
		"r0", "r1", "r2", "r3", "r4", "r5","r6", "r7",
		"r8", "r9", "r10", "r11", "r12", "lr","sp", "pc"
	};

	for (int i = 0; i < sizeof(regnames) / sizeof(char*); i++) {
		w.gotorc(1+i, 50);
		//		t.setLowColor(1, i);
		w.setColor(0x00FF00, 0x000000);
		w << regnames[i];
		if (i > 5)
			w.setColor(0xFFFFFF, 0x000060);
        if (i < 7)
			w.blink();
		w.printHex(1+i, 54, 0xA0203f34);
	}

	for (int i = 0; i < 100; i++) {
		time_t now = time(nullptr);
		w.print(25, 0, uint64_t(now));
		w.flush();
		sleep(1);
	}	
}

int main() {
  test1();
}