/* 

Inheritance does not solve all problems

class Shape {

};

class Sphere : public Shape{
};

class Cylinder : public Shape {

};


class Airplane {

};

class PassengerPlane : public Airplane {

};

class B757A : public PassengerPlane {

};

class B757A_100 : public B757A {

};

*/

template<typename T>
class Complex {
private:
	T r, i;
};
