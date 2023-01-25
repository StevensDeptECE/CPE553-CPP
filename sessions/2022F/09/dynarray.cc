#include <iostream>
using namespace std;

// list of int
class dynarray {
private:
  int* data;
  uint32_t len;
  // 4 bytes of dead space here..
public:
  dynarray(): data(nullptr), len(0) { // use this. But know NULL and 0    
  }

  ~dynarray() {
    delete [] data;    
  }
  void add(int val){
    // old= 2 3
    const int* old = data;
    data = new int[len+1]; // _2_, _3_, _v_
    for (int i = 0; i < len; i++)
      data[i] = old[i]; // copy all the old memory
    data[len] = val;
    len++; // now we have len+1 elements
    delete [] old;
  }
  
};

int main() {
  dynarray a;
  a.add(3);
  a.add(1);
  for (int i=0; i < 1000000; i++)
   a.add(i);
  cout << a << '\n';
  //dynarray b = a;
}

