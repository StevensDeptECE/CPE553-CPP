
# CPE553 Review

1. Primitive data types
  a. int, short, long, char (legacy)
  b. uint8_t, uint16_t, uint32_t uint64_t, int8_t, int16_t, int32_t int64_t
  c. char s[]
  d. pointers

```cpp
int a = 5 / 2 * 3;
double b = 7 / 2 * 4;
double c = 7 / 2 * 4.0;
double d = 7 / 2.0 * 4;
int e = 3 % 4 + 4 % 3 + 5 % 6;
// bitwise ops NOT ON TEST
uint64_t f = 1 << 4; // 000000010000
uint64_t g = 1 << 32;
uint64_t h = 1ULL << 32;
uint64_t i = 0x2C >> 4;// 0010 1100
// 00000000000000000000000000000000010
uint64_t j = 0x2C & 0x3B;
// 0x2C = 0010 1100
// 0x3B = 0011 1011
//        0010 1000 = 0x28 = 40
uint64_t j = 0x2B | ~0x2B; // 0xFFFFFFFF
uint64_t k = 0x5A ^ 0x16;
//   0101 1010
//   0001 0110
//   0100 1100 = 0x4C
int xx = 5;
const int* p = &xx; //LEGAL
xx = 6;
const int yy = 7;
int* q = &yy; // ERROR   * NOT ON TEST!
*q = 99;                 * NOT ON TEST!
```
2. Functions
  a. passing parameters by value
  b. passing parameters by reference
  c. passing arrays (pointers)
  d. passing pointer to pointer* NOT ON TEST
```cpp
void f(const char s[]) {
  //sizeof(s) is ALWAYS 8
  //strlen(s)
}

uint64_t readFile(const char filename[], uint8_t** p) {
    ifstream f(filename);
    f.seekg(ios::end, 0)
    size_t len = f.tellg();
    *p = new uint8_t[len];
    return len;
}


int main() {
    uint8_t* p;
    size_t len = readFile("myfile", &p);

    ...
    delete []p;

    //unique_ptr<> remembers to free memory for you
}
```
3. Object-Oriented Programming
  a. class, object, message, method
  b. member, member function, friend
  c. inheritance : public A {}, : private A {}, : protected A {}, : public virtual A {}
  d. separate compilation *NOT ON TEST
```cpp
class A {};
A a1;

class B {
public:
     B(int){}
};
B b1; // illegal
B b2 = b1; // by default, copy constructor is created

class C {
    int a;
    char b;
    double c;
};

C c1;
C c2 = c1; // makes a copy of the garbage in c1
```
4. Generic Programming
  a. template fuinction
  b. template class with no dynamic memory
     complex<double> a;  complex<float> b;
     template<typename T>
     class complex {
     public:
       T real, imag;
     };

5. Library classes
  a. vector
  b. unordered_map
  c. regex * NOT ON FINAL

6. Dynamic Memory
  a. new/delete
    1. whatever you new, you must delete
    2. don't delete twice
    3. delete only the pointer you were given
    4. don't delete pointers to objects on the stack
    5. don't return a pointer to something that will disappear
```cpp
  int* f() {
    int a[10];
    for (int i = 0; i < 10; i++)
      a[i] = i;
    return a;
  }
```
  b. malloc/free
  c. classes containing dynamic memory: constructor, destructor
     copy constructor, operator =
  d. move constructor is extra (bonus)
 
 ```cpp
class A {
private:
  int* p;
  public:
   A() { p = new int[100]; }
   ~A() { delete [] p; }
   A(const A& orig) : p(new int[100]) {
    for (int i = 0; i < 100; i++)
      p[i] = orig.p[i];
   }
   A& operator =(A copy) {
    swap(p, copy.p);
   }
   A(A&& orig) p(orig.p) {
    orig.p = nullptr;
   }
};

//std::move( ) --> calls the move constructor
A f() {
  A a1;
  return a1;
}

 ```