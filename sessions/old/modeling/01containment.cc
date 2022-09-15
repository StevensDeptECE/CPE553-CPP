class Heart {
private:
	int systolic, diastolic, bpm;
public:
	Heart(int systolic, int diastolic, int bpm) :
		systolic(systolic), diastolic(diastolic), bpm(bpm) {}
};

class Kidney {
private:
	int percentFunction;
public:
	Kidney(int percentFunction) : percentFunction(percentFunction) {}
};

class Person {
private:
	Heart h;
	Kidney k1,k2;
public:
	Person() : h(120,70,65), k1(100), k2(100) {}
};
