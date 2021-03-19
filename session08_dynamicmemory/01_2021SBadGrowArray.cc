#include <iostream>
using namespace std;
/*
  Resources Allocation is Initializtion
*/
class BadGrowArray {
  private:
    int* arr;
    int size;
  public:
    BadGrowArray() : arr(nullptr), size(0)  {}
    ~BadGrowArray() { delete[] arr; }

    BadGrowArray(const BadGrowArray& orig) : arr(new int[orig.size]), size(orig.size) {
      for (int i = 0; i < size; i++)
        arr[i] = orig.arr[i];
    }
#if 0
//old school operator =
    BadGrowArray& operator =(const BadGrowArray& orig) {
      if (this != &orig) {
        delete [] arr;
        arr = new int[orig.size];
        size = orig.size;
        for (int i = 0; i < size; i++)
          arr[i] = orig.arr[i];
      }
      return *this;
    }
#endif
//copy and swap
    BadGrowArray& operator =(BadGrowArray copy) {
      size = copy.size;
      swap(arr, copy.arr);
    }


    void addEnd(int n) {
      int* temp = new int[size+1]; // make new array temp of size 1 larger than arr
      
      for(int i = 0; i < size; i++) {
        temp[i] = arr[i]; // copy all elements of arr to temp
      }
      temp[size++] = n; // assign n to end of temp and increment size after this assign (post-increment)

      delete[] arr; // delete old arr
      arr = temp; // assign private arr to the temp array created above
    }
    
    void addStart(int n) {
      int* temp = new int[size+1];
      temp[0] = n;
      for(int i = 1; i <= size; i++)
          temp[i] = arr[i - 1];
          
      delete[] arr;
      arr = temp;
      size++;
    }

  friend ostream& operator <<(ostream& s, const BadGrowArray& a) {
    for( int i = 0; i < a.size; i++) {
      s << a.arr[i] << " ";
    }
    return s;
  }
};
void f(int n) {
  int x;
  BadGrowArray a; // create an empty list of int
  int y[10];
  // 1 + 2 + 3 + .. + n = n(n+1)/2 = O(n^2)
  a.addEnd(3);
  a.addStart(1);
  cout << a << '\n';
  BadGrowArray b = a; // these call the copy constructor
  BadGrowArray c(a);
  c.addEnd(2);

  c = a; // operator =
//  BadGrowArray *p = &a;
//  BadGrowArray* q = &a;
//  *p = *q;
  a = a;

  if (n > 0) 
    f(n-1);
}


int main() {
  int x[127];
  f(0);
}