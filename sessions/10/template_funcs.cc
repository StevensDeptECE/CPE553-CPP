#include <iostream>
#include <string>
using namespace std;
// 10 9 8 7 6 5 4 3 2 1
// 9 8 7  6 5 4 3 2 1 10

template<typename T>
void bubbleSort(T x[], int len) {
  for (int j = 0; j < len-1; j++)
    for (int i = 0; i < len-1; i++)
      if (x[i] > x[i+1]) {
        swap(x[i], x[i+1]);
      }
}
template<typename T, typename Key>
void bubbleSort(T x[], int len, Key T::*k) {
  for (int j = 0; j < len-1; j++)
    for (int i = 0; i < len-1; i++)
      if (x[i].*k > x[i+1].*k) {
        swap(x[i], x[i+1]);
      }
}


#if 0
void print(T x[], int len) {

}
#endif

class Elephant {
public:
    string name;
    int age;
    friend bool operator >(const Elephant& a, const Elephant& b) {
        return a.age > b.age;
    }
};

int main() {
    int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    double b[] = { 10.5, 9.1, 8, 7, 6.1, 5, 4, 3, 2, 1.1 };
    string c[] = { 
        "hello", "cat", "elephant", "dog"
    };
    Elephant d[] = { {"Fred", 5}, {"Alice", 17}, {"James", 2}};
    // type unification, T=int
    bubbleSort(a, sizeof(a)/sizeof(int));
    //print(a);
    bubbleSort(b, sizeof(b)/sizeof(double));
    //print(b);
    bubbleSort(d, sizeof(d)/sizeof(Elephant), &Elephant::age);
//    bubbleSort(c, sizeof(a)/sizeof(int));
//    print(c);
//https://www.cppstories.com/2021/concepts-intro/
}