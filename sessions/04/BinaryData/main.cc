
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

class BinaryObject {
public:
  virtual void write(ostream& f) = 0;
};



class Address : public BinaryObject {

private:
    char firstName[20];
    char lastName[24];
    char address[50];
    int phoneNumber;

public:  
    Address(const char firstName[], const char lastName[], const char address[], int phoneNumber) :
        phoneNumber(phoneNumber) {
            strcpy(this->firstName, firstName);
            strcpy(this->lastName, lastName);
            strcpy(this->address, address);
        }
    
    void write(ostream& f) {
      f.write((char*)this + 8, sizeof(Address)-8);
    }
};




class Stock : public BinaryObject {
  private:
    char name[16];
    float value;
    
  public:
    Stock(const char n[], float v) : value(v) {
      strcpy(name, n);
    }

    void write(ostream& f) {
      f.write((char*)this + 8, sizeof(Stock)-8);
    }



};

class Circle : public BinaryObject{
private:
    double x;
    double y;
    double r;

public:
    Circle(double x, double y, double z) : x(x), y(y), r(r) {}

    void write(ostream& f) {
      f.write((char*)this + 8, sizeof(Circle)-8);        
    }



};


int main() {
  Address a("Dov", "Kruger", "1313 Mockingbird Lane", 2015551232);
  Stock b("IBM", 182.65);
  Circle c(128.2, 240.8, 55.9);


  ofstream f("file.bin", ios::binary);
  BinaryObject* arr[3] {&a, &b, &c};

  a.write(f);
  b.write(f);
  c.write(f);

  for (int i = 0; i < 3; i++)
    arr[i]->write(f); // polymorphism: "whoever you are, write yourself to disk"

}
