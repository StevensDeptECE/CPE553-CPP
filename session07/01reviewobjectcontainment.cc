class Vehicle {
private:
	int speed;
public:
	Vehicle(int speed) : speed(speed) {}
};

class Engine {
public:
	Engine(double hp) {}
};

class Wheel {
public:
	Wheel(int p) {}
};

class Car : public Vehicle {
private:
	Engine e;
	Wheel w1, w2, w3, w4;
	//	Wheel w[4];
public:
	Car(int speed, double hp, int p1, int p2, int p3, int p4) :
		Vehicle(speed), e(hp), w1(p1), w2(p2), w3(p3), w4(p4) {}
};
/*
	Vehicle has a speed
	Car inherits from Vehicle
	 Car has an engine
  Engine has a horsepower (double)
  Car has 4 wheels
  Wheel has a tire pressure

 */
int main() {
	Car c1(55, 480, 28, 29, 31, 31);

}
