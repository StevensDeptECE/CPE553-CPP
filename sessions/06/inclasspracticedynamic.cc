#include <iostream>
using namespace std;

/*
  1. Whatever you allocate you must free
  1b. Do not deallocate that which was not allocated
  2. do not free the same memory twice
  3. malloc matches with free, new matches with delete. You cannot mix and match
  4. delete only the pointer that was allocated. it must not be changed
  5. do not write outside the bounds!


*/


int main() {
  int a;
//  delete &a; // this was not allocated with new, must not delete

  int* p;
  p = (int*)malloc(10*sizeof(int));
  for(int i=0; i<10; i++) {
      p[i] = i;
  }
  for(int i=0; i<10; i++) {
      cout << p[i] << endl;
  }
  free(p);
  //free(p);
  








  int* q;
  q = new int[10];
  
  for(int j=0; j<10; j++) {
      q[j] = j;
  }
  delete [] q;
  

  cout << q[0] <<'\n';


  q = new int[20];
  int*r = q;
  for (int i = 0; i < 20; i++)
    *q++ = i;
  delete [] r;

  q = new int[20];
  cout << q[-2] << ' ' << q[-1] << '\n';
  q[-2] = 912519259;
  delete [] q;
}


