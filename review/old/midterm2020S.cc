/*

1. Write a class BitMap:

Bitmap b(1024,768);
b(2,2) = 5;
b.rect(10,20,30,40);


1b. Write a class List:
...

2. Write a class Vec3d:


Vec3d a(1,2,3);
Vec3d b(1.5, 2.1,-1.6);
double d = dot(a,b);
double d2 = Vec3d::dot(a,b); // static
double d3 = a.dot(b); // method or member function

Vec3d c = a + b;
Vec3d d = c * 2; (2cx,2cy,2cz)


2b. Write class Complex...

3. Write a function to return the count of all prime numbers up to n that have no digits 7.
//110613
bool containsDigit(int n, int d) {
do {
 int rightDigit =   n % 10;
 if (rightDigit == d)
   return true;
 n/= 10;
} while (n > 0);
  return false;
}

Write a function init() to take an array of integers, a length, and store a value into all elements using pointers

void init(int* x, int len, int val) {

}


init(x, 100, 3);


 */
