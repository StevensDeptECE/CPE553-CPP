#include <iostream>
using namespace std;


class Airplane {
public:
	void fly() {
		cout << "flap, flap";
	}
};

class PassengerAirplane : public Airplane {
public:
	void serveCoffee();
	void serveCoronaVirus();
};

class FighterPlane : public Airplane {
private:
	int bullets;
public:
	FighterPlane() : bullets(100) {}
	void shoot() {
		cout << bullets << "Remaining\n";
		bullets--;
	}
};

int main() {
	Airplane a1;
	a1.fly();
	FighterPlane f1;
	//	f1.fly();
	f1.shoot();
	//illegal	a1.shoot();

	// illegal cast of child pointer to parent
	FighterPlane *fp = (FighterPlane*)&a1;
	fp->shoot();
}
