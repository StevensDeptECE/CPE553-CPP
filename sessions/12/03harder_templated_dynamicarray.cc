#include <iostream>
using namespace std;

template<typename T>
class dynamicarray {
    private:
      char* a; // first, we don't admit we are pointing to T
      uint32_t size;
    //placement new
    void* operator new(size_t size, void* mem) {
        return mem;
    }
    public:
      dynamicarray() : a(nullptr), size(0) {}
      ~dynamicarray() { delete [] a; }
      dynamicarray(const dynamicarray& orig) : 
        a(new char[orig.size*sizeof(T)]), size(orig.size) {
            for (int i = 0; i < size; i++)
              new (a + i * sizeof(T)) T(orig.a[i]); // call copy constructor, dest = a[i] 
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
        const T* old = (const T*)a;
        a = new char[(size+1)*sizeof(T)];
        for (int i = 0; i < size; i++)
          new (a + i * sizeof(T)) T(old[i]); // make a copy OVER THERE
        delete [] (char*)old;
        new (a + size*sizeof(T)) T(v);
        size++;
      }
      friend ostream& operator <<(ostream& s, const dynamicarray& a) {
        for (int i = 0; i < a.size; i++)
          s << a.a[i] << ' ';
        return s;
      }
};

int main() {
    #if 0
    dynamicarray<int> a;
    a.add(5);
    a.add(9);
    cout << a << '\n';

    dynamicarray<double> b;
    b.add(2.5);
    for (int i = 0; i < 10; i++)
      b.add(i + 0.5);
    cout << b << '\n';
#endif
    dynamicarray<string> c;
    c.add("hello this is a big big big string");
    c.add("test tesing testing 123 hello are you there?");
    cout << c << '\n';

}