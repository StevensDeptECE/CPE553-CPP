class Vehicle {
private:
	int speed;
public:
	Vehicle(int speed) : speed(speed) {}
};

class Engine {
private:
	doubel hp;
public:
	Engine(double hp) : hp(hp) {}
};

class Wheel {
private:
	int pressure;
public:
	Wheel(int p) : pressure(p) {}
};

class Car : public Vehicle {
private:
	Engine e;
	Wheel w1, w2, w3, w4;
	//	Wheel w[4];
public:
	Car(int speed, double hp, int pfront, int pback) :
		Vehicle(speed), e(hp), w1(pfront), w2(pfront),w3(pback), w4(pback)  {}
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
	Car c1(55, 480.0, 28, 31);

}
