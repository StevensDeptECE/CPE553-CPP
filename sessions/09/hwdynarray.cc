#include <iostream>
using namespace std;

class DynArray {
    private:
    int* data;
    uint32_t len;
    uint32_t capacity;
    grow should double the size of the list and copy all the old into the new
    void grow() {

    }
    public:
    DynArray(uint32_t capacity);
    void add(int v);
    ~DynArray();
    friend ostream& operator <<(ostream& s, const DynArray& d) {

    }
};

int main() {
  DynArray a(100); // preallocate 100 size
  for (int i = 0; i < 100; i++)
    a.add(i); // this should take O(100) time
  a.add(101);
  cout << a;
}