#include <iostream>
#include <string>
using namespace std;

template<typename T>
class DynArray {
private:
  T* arr;
  uint32_t size;
//  uint32_t capacity;
  void* operator new(size_t size, void* loc) {
    return loc;
  }
public:
  DynArray() : arr(nullptr), size(0) {}
  ~DynArray() {
     delete [] arr;      
  }
  DynArray(const DynArray& orig) = delete;
  DynArray& operator =(DynArray copy) = delete;
  DynArray(DynArray&& orig) : arr(orig.arr), size(orig.size) {
    orig.arr = nullptr;
    orig.size = 0;
  }

  void add(const T& v) {
    const T* old = arr;
    arr = (T*)new char[(size+1)*sizeof(T)]; // T::T()
    char* temp = (char*) arr;
    for (uint32_t i = 0; i < size; i++, temp += sizeof(T))
      std::move(arr[i], old[i]);
      //new(temp) T(old[i]); // this SHOULD do a move?
    //new (temp) T(v);
    std::move(arr[size], v)
    size++;
    delete [] (char*)old;
  }
  friend ostream& operator <<(ostream& s, const DynArray& list) {
    for (uint32_t i = 0; i < list.size; i++)
      s << list.arr[i] << ' ';
    return s;
  }
};

DynArray<string> f(int n) {
  DynArray<string> ans;
  for (int i = 0; i < n; i++)
    ans.add("this is too long!");
  return ans;
}

int main() {
    DynArray<int> a;
    for (int i = 0; i < 10; i++)
      a.add(i);
    cout << a << '\n';

    DynArray<double> b;
    for (int i = 0; i < 10; i++)
      b.add(i+0.5);
    cout << b << '\n';

    DynArray<string> c;
    c.add("x");
    c.add("y");
    c.add("zzzz");
    cout << c << '\n';

    DynArray<string> d = f(10);
    cout << d << '\n';
}