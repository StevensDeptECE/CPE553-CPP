class Engine {
private:
	int hp;
public:
	Engine(int hp) : hp(hp) {}
};
class Wheel {
private:
	int p;
public:
	Wheel(int p) : p(p) {}
};

class Vehicle {
private:
	int speed;
public:
	Vehicle(int speed) : speed(speed) {}
	int getSpeed() const { return speed; }
};
		
class Car : public Vehicle {
private:
	Engine e;
	Wheel w1,w2,w3,w4;
public:
	Car(int speed, int hp, int frontPressure = 28, int BackPressure = 30) :
		Vehicle(speed), e(hp), w1(frontPressure), w2(frontPressure),
		w3(backPressure), w4(backPressure) {}
};

int main(){
	Car c1(55, 280, 28, 30);

}

