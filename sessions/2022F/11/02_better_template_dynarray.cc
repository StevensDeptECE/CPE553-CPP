#include <iostream>
#include <string>
using namespace std;

// list of T


template<typename T>
class baddynarray {
private:
  char* data; // just bytes
  uint32_t len;
public:
  baddynarray(): data(nullptr), len(0) {
  }
  ~baddynarray() {
    delete [] (T*)data;    
  }
  baddynarray(const baddynarray& orig) : data(new char[orig.len*sizeof(T)]), len(orig.len) {   // dynarray<T>::dynarray
    for (int i = 0; i < len; i++)
      new(data+i*sizeof(T)) T(orig.data[i]);
  }
  void* operator new (size_t sz, void* ptr) {
    return ptr;
  }
  baddynarray& operator =(baddynarray<T> copy) {
    len = copy.len;
    swap(data, copy.data);
    return *this;
  }
  void add(const T& val){
    const T* old = (const T*)data;
    data = new char[(len+1)*sizeof(T)];
    for (int i = 0; i < len; i++)
      new (data+i*sizeof(T)) T(old[i]); // copy all the old memory
    new (data+len*sizeof(T)) T(val);
    len++; // now we have len+1 elements
    delete [] (char*)old;
  }
  friend ostream& operator <<(ostream& s, const baddynarray& list) {
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
  ~Elephant() {
    cout << "dying " << name << " dying\n";
  }
  Elephant(const string& name) : name(name) {}
  friend ostream& operator <<(ostream& s, const Elephant& e) {
    return s << "Elephant << " << e.name;
  }  
};

int main() {
  baddynarray<int> a;
  a.add(3);
  a.add(1);
  for (int i=0; i < 10; i++)
   a.add(i);
  cout << a << '\n';
  baddynarray<int> b = a;
  baddynarray<int> c = a;

  c = a; // test operator =

  baddynarray<Elephant> elephants;
  elephants.add(Elephant("Eve"));
  elephants.add(Elephant("Alice"));
  elephants.add(Elephant("Bob"));
  cout << elephants << '\n';
}

