#include <iostream>
using namespace std;

template<typename T>
class dynamicarray {
    private:
      T* a;
      uint32_t size;
    public:
      dynamicarray() : a(nullptr), size(0) {}
      ~dynamicarray() { delete [] a; }
      dynamicarray(const dynamicarray& orig) : 
        a(new T[orig.size]), size(orig.size) {
            for (int i = 0; i < size; i++)
              a[i] = orig.a[i];
        }
      dynamicarray& operator =(dynamicarray copy) {
        size = copy.size;
        swap(a, copy.a);
        return *this;
      }
      dynamicarray(dynamicarray&& orig) : a(orig.a), size(orig.size) {
        orig.a = nullptr;
      }
      void add(const T& v) {
        const T* old = a;
        a = new T[size+1];
        for (int i = 0; i < size; i++)
          a[i] = old[i];
        delete [] old;
        a[size] = v;
        size++;
      }
      friend ostream& operator <<(ostream& s, const dynamicarray& a) {
        for (int i = 0; i < a.size; i++)
          s << a.a[i] << ' ';
        return s;
      }
};

int main() {
    dynamicarray<int> a;
    a.add(5);
    a.add(9);
    cout << a << '\n';

    dynamicarray<double> b;
    b.add(2.5);
    for (int i = 0; i < 10; i++)
      b.add(i + 0.5);
    cout << b << '\n';

    dynamicarray<string> c;
    c.add("hello");
    c.add("test");
    cout << c << '\n';

}