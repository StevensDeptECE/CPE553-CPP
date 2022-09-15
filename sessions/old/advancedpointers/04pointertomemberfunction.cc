#include <iostream>
using namespace std;

class Alarm {
public:
	void fire(int zone);
	void burgler(int zone);
};

void Alarm::fire(int zone) {
	cout << "Fire in zone " << zone << '\n';
}

void Alarm::burgler(int zone) {
	cout << "Burgler in zone " << zone << '\n';
}


int main() {
	// simulate an event from an alarm

	Alarm a;
	char type;
	int zone;
	cin >> type >> zone;
	switch(type) {
	case 'f':
		a.fire(zone);
		break;
	case 'b':
		a.burgler(zone);
		break;
	default:
		cout << "Unknown alarm";
		break;
	}

	// or another way:
	void (Alarm::*p)(int);
	switch(type) {
	case 'f': p = &Alarm::fire; break;
	case 'b': p = &Alarm::burgler; break;
	default: break;
	}
	(a.*p)(zone); // call the appropriate method based on the pointer
	Alarm* q = &a;
	(q->*p)(zone);
}

	
