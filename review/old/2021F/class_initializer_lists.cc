#include <iostream>
using namespace std;

class kidney {
private:
	double health;
public:
	// kidney function 0 to 100%
	kidney(double health) : health(health) {}
	friend ostream& operator <<(ostream& s, kidney k) {
		return s << "health=" << k.health;
	}
};

class heart {
private:
	uint16_t beats_per_minute;	// store the core heart health parameters
	uint16_t systolic;
	uint16_t diastolic;
public:
	heart(uint16_t bpm, uint16_t sys, uint16_t dia)
		: beats_per_minute(bpm), systolic(sys), diastolic(dia) {}
	friend ostream& operator <<(ostream& s, heart h) {
		return s << "bpm=" << h.beats_per_minute <<
			" blood pressure=" << h.systolic << "/" << h.diastolic;
	}
};

class person {
private:
	kidney k1,k2;
	heart h;
public:
	person(uint16_t bpm, uint16_t systolic, uint16_t diastolic,
				 uint16_t left_kidney_health, uint16_t right_kidney_health)
		: k1(left_kidney_health), k2(right_kidney_health),
			h(bpm, systolic, diastolic) {}
	friend ostream& operator <<(ostream& s, const person& p);
};

ostream& operator <<(ostream& s, const person& p) {
	return s << "person " << p.h << " left " << p.k1 << " right " << p.k2;
}

int main() {
  person p(60, 125, 75, 100, 100); // this should print nothing

  cout << "now here comes the output\n";

	cout << p << '\n'; // this print should output the following
	// person bpm=60 blood pressure=125/75 left kidney=100 right kidney=100
}
