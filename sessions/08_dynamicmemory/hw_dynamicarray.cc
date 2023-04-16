#include <iostream>
using namespace std;

/*
  homework for dynamic arrays.
  Create a dynamic array that allocates a big chunk of memory, unlike the one in class

*/
class dynamicarray {
private:
  int* p;
  uint32_t capacity; // this is the size of the block you allocate
  uint32_t size;     // this is the size of the list which can be from 0 to capacity
  void grow() { // double the list in size
    const int* old = p;
    p = new int[capacity*2];
    //TODO:
  }
public:
//TODO; complete the constructor
  dynamicarray(uint32_t capacity) : _______________________ {  }
  ~dynamicarray() {
    delete [] p;
  }
  // TODO: complete the copy constructor
  dynamicarray(const dynamicarray& orig) : ___________________________ { 
    //TODO: complete
  }

  //TODO: write the move constructor
  dynamicarray(dynamicarray&& orig) : ________________ {

  }
  
  // copy and swap paradigm
  dynamicarray& operator =(dynamicarray copy) {
    size = copy.size;
    capacity = copy.capacity;
    swap(this->p, copy.p);
    return *this; // return the destination by reference
  }

  void add(int v) {
    if (size >= capacity)
      grow(); // grow should allocate twice the storage and then delete the old memory
    //TODO: complete

  }
  friend ostream& operator <<(ostream& s, const dynamicarray& a) {
    //TODO: print out all elements in the array separated by spaces

    return s;
  }
};

void f(dynamicarray x) {
  cout << "this makes a copy of the parameter x. Will crash if you don't write copy constructor\n";
}

dynamicarray g(int size) {
  dynamicarray temp(size);
  for (int i = 0; i < size; i++)
    temp.add(i*2);  // 0 2 4 6 8 10...
  return temp; // returns a copy of temp, will crash if you don't write copy constructor
}

int main() {
  dynamicarray a(50); // preallocate 50 elements, list is empty
  for (int i = 0; i < 20; i++)
    a.add(i); // add the number i to the end of the list    0 1 2 3
  cout << a << '\n';

  dynamicarray b = a; // b is a copy of a (calls copy constructor)
  dynamicarray c(a); // b is a copy of a (calls copy constructor)
  cout << c << '\n';
  dynamicarray e(2);
  e.add(7); // create an array with just 1 element
  c = e; // this should give back the 10 elements, then copy e
  cout << c << '\n'; // should print only 7
  e = e;
  cout << e << '\n'; // should also print only 7
  f(c);
  dynamicarray d = g(5); // 0 2 4 6 8
  d = e = c; // first copies e=c, then copy d=e
}