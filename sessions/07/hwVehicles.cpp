/*
    cars pay $20
    Trucks pay $20 * number of axles
    Bus pays $4
*/

int main() {
    
    Car c(55, "red");
    Truck t(90, 10000.0, 3);// 90mph, 10000 lbs, 3 axles
    Bus b(28, 40); //28 miles per hour, 40 passengers

    const Vehicle* vehicles[] = {&c, &t, &b};
    const int n = sizeof(vehicles)/sizeof(const Vehicle*);
    for (int i = 0; i < n; i++) {
      (*vehicles[i]).payToll(); // polymorphism
      vehicles[i]->payToll();
    }
    for (auto v : vehicles)
      v->payToll();
    for (auto v : vehicles)
      v->print();       // print the state of your object

    for (auto v : vehicles)
      cout << *v;       // in Vehicle define friend operator <<( ) to call print()
}