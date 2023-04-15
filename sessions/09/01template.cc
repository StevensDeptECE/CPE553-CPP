#include <iostream>
using namespace std;
// 5 4 3 2 1
// 4 3 2 1 5
// 3 2 1 4 5
void sort(int a[], uint32_t len) {
  for (int j = 0; j < len-1; j++) {
      for (int i = 0; i < len-1; i++)
        if (a[i] > a[i+1]) {
//        swap(a[i], a[i+1]);
            int temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
  }
}

void print(const int a[], uint32_t len) {
    for (int i = 0; i < len; i++)
      cout << a[i] << ' ';
    cout << '\n';
}

template<typename T>
void sort2(T a[], uint32_t len) {
  for (int j = 0; j < len-1; j++) {
      for (int i = 0; i < len-1; i++)
        if (a[i] > a[i+1]) {
            T temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
  }
}

template<typename T>
void print2(const T a[], uint32_t len) {
    for (int i = 0; i < len; i++)
      cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    int x[] = { 5, 4, 9, 3, 2, 1};
    constexpr int n = sizeof(x)/sizeof(int);
    //sort(x, n);
    //print(x, n);

    sort2(x, n);
    print2(x, n);

    double y[] = {2, 1.5, 7.1, 3.5, 6.2} ;
    sort2(y, 5);
    print2(y, 5);

#if 0
    string z[] = {"hello", "cat", "zebra", "apple"};
    sort2(z, sizeof(z)/sizeof(string));
    print2(z, sizeof(z)/sizeof(string));
#endif
}
