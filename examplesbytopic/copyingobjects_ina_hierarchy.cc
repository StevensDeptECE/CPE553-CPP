#include <iostream>
using namespace std;

class Airplane {
    public:
        double fuel;
    public:
        Airplane(double fuel) : fuel(fuel) {}
        Airplane(const Airplane& orig) : fuel(orig.fuel) {}
        void fly() {}
};

class FighterPlane : public Airplane {
    public:
        int ammunition;
    public:
        FighterPlane(double fuel, int ammo) : Airplane(fuel), ammunition(ammo) {}
};

class PassengerPlane : public Airplane {
    public:
        int coffee;
    public:
        PassengerPlane(double fuel, int coffee) : Airplane(fuel), coffee(coffee) {}
};

int main() {
    FighterPlane* fp = new FighterPlane(100, 50);
    cout << fp->fuel << " " << fp->ammunition << '\n';
    FighterPlane* fp2 = (FighterPlane*) new Airplane(*fp);
    cout << fp2->fuel << " " << fp2->ammunition << '\n';
}
