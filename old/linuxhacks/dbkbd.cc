/*
 * dbkbd.c
 *
 *  Created on: Feb 10, 2019
 *      Author: pho
 * converterd to C++ Dov Kruger Feb 13
 */
#include <iostream>

#include <stdio.h>
//#include <stdlib.h>
#include <string>
#include <vector>
#include <unistd.h>
#include <linux/input.h>
#include <fcntl.h>
//#include <xdo.h>
//#include <signal.h>
//#include "keytables.h"
//#include "special.h"
using namespace std;

class Inputs {
private:
	// grab USB keyboard devices
	const static char *command;
	struct Keyboard {
		int fh;
		string name;
		Keyboard(const string& name) : name(name) {
			fh = open(name.c_str(), O_RDONLY);
			if (fh < 0) {
				throw "keyboard failed to open";
			}
			int flags = fcntl(fh, F_GETFL, 0); // first read the flags currently on the keyboard
			fcntl(fh, F_SETFL, flags | O_NONBLOCK);  // then or in the nonblocking bit
		}
	};
	vector<Keyboard> keyboards;

	void getDevices() {
    	FILE *grep_devices_p = popen(command, "r");
			char keyboardNameBuf[16];
			const string prefix = "/dev/input/";
			for (int i = 0; NULL != (fgets(keyboardNameBuf, 9, grep_devices_p))	&& i < 10; ++i) {
				try {
					int j;
					for (j = 0; keyboardNameBuf[j] != '\n'; j++)
						;
					keyboardNameBuf[j] = '\0'; // remove the newline at the end
					keyboards.push_back(Keyboard(prefix + keyboardNameBuf));
				} catch (const char* msg) {
					cerr << msg << '\n';
				}
			}
			pclose(grep_devices_p);
	}
public:
	Inputs() {
		getDevices();
	}
	friend ostream& operator <<(ostream& s, const Inputs& inp) {
		for (auto k : inp.keyboards) {
			cout << k.name << '\n';
		}
		return s;
	}
};

const char* Inputs::command =
			"grep -E 'Handlers|EV=' /proc/bus/input/devices | grep -B1 'EV=120013' | grep -Eo 'event[0-9]+'";
Inputs inputs;
int main() {
  cout << inputs;  
}
