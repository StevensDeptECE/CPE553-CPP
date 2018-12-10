#include <iostream>

class Alarm {
public:
	void fire(int zone);
	void burgler(int zone);
};

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
	void A::(*p)(int);
	switch(type) {
	case 'f': p = &A::fire; break;
	case 'b': p = &A::burgler; break;
	default:: break;
	}
	a.*p(zone); // call the appropriate method based on the pointer
}

	
