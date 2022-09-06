class Heart {
private: // default is private.  all data SHOULD be private unless you have a good reason
	int bpm, systolic, diastolic;
protected:
	
public:
	Heart(int bpm, int systolic, int diastolic) {}

	int getBeats() const { return bpm; }
};

class Kidney {
private:
	int health;
public:
	int getHealth() const { return health; }
};


class Person : public Heart {
private:
	Kidney k1, k2;
public:
	
};

Person p1;
p1.k1.getHealth() = 100;
p1.k2.health = 77;


class Pilot : public Airplane {

};


