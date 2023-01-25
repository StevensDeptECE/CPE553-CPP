#include <iostream>
#include <string>
using namespace std;

// list of T

template<typename T>
class dynarray {
private:
  T* data;
  uint32_t len;
public:
  dynarray(): data(nullptr), len(0) {
  }
  ~dynarray() {
    delete [] data;    
  }
  dynarray(const dynarray& orig) : data(new T[orig.len]), len(orig.len) {   // dynarray<T>::dynarray

  }
  dynarray& operator =(const dynarray<T>& orig) {
    
  }
  void add(const T& val){
    const T* old = data;
    data = new T[len+1];  // calls T::T()
    for (int i = 0; i < len; i++)
      data[i] = old[i]; // copy all the old memory
    data[len] = val;
    len++; // now we have len+1 elements
    delete [] old;
  }
  friend ostream& operator <<(ostream& s, const dynarray& list) {
    for (int i = 0; i < list.len; i++)
      s << list.data[i] << ' ';
    return s;
  }  
};

class Elephant {
private:
    string name;
public:
  Elephant() : name("") {}
  Elephant(const string& name) : name(name) {}
  friend ostream& operator <<(ostream& s, const Elephant& e) {
    return s << "Elephant << " << e.name;
  }  
};

int main() {
  dynarray<int> a;
  a.add(3);
  a.add(1);
  for (int i=0; i < 10; i++)
   a.add(i);
  cout << a << '\n';
  dynarray<int> b = a;
  dynarray<int> c = a;

  dynarray<Elephant> elephants;
  elephants.add(Elephant("Eve"));
  elephants.add(Elephant("Alice"));
  elephants.add(Elephant("Bob"));
  cout << elephants;
}

