/*
	Person
	  heart = BPM  systolic, diastolic 120/70 
		2 kidneys = 0% 100%  if both kidneys = 0% person dies


 */

class Person  {
private:
	Heart h;
	Kidney k[2];
public:

};


/*
	Person  own 1 car
	Car can be owned by a person
*/

class Person {
private:
	Car* c;
public:
	Person() : c(nullptr) {}
	void buy(Car c) 
};

Person owns 0 to many cars
Car owned by multiple people
Police want to be able to find:

class Car;

class Person {
private:
	vector<Car*> cars;

};


class Car : public Vehicle {
private:
	vector<Person*> owners;
