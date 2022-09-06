class Airplane {
public:
	void fly();
};

class Pilot {
private:
	Airplane* controlling;
public:
	void fly()  {
		if (controlling != nullptr)
			controlling->fly();
	}
};



/*
	Person name

	Heart  bpm systolic/diastolic

	Kidney %working

 */

class Person {
private:
  Kidney k1, k2;
	Heart h;
public:
};
