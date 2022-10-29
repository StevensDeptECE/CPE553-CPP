#include <iostream>
#include <string>
#include <vector>
//#include "benchmark.hh"
using namespace std;
string copy1(const string& s) {
  return s;
}

void test1(uint32_t n) {
    string s = "abcd";
    for (uint32_t i = 0; i < n; i++)
      s = copy1(s);
}

void test2(uint32_t n) {
    string s;
    for (uint32_t i = 0; i < n; i++)
      s += 'x';
}

void test3(uint32_t n) {
    string s;
    s.reserve(n); // preallocate the right amount of space
    for (uint32_t i = 0; i < n; i++)
      s += 'x';
}

void test4(uint32_t n) {
    vector<int> a;
    for (uint32_t i = 0; i < n; i++)
      a.push_back(i);
}

void test5(uint32_t n) {
    vector<int> a;
    a.reserve(n); // preallocate the right amount of space
    for (uint32_t i = 0; i < n; i++)
      a.push_back(i);
}

#include "vec3d_inline.hh"
#include "vec3d.hh"

void test6(uint32_t n) {
    vector<vec3d_inline> v;
    for (int i = 0; i < n; i++)
      v.push_back(vec3d_inline(1,2,3));
}

void test7(uint32_t n) {
    vector<vec3d> v;
    for (int i = 0; i < n; i++)
      v.push_back(vec3d(1,2,3));
}

// add n vectors and return the magnitude using non-inline object
double test8(uint32_t n) {
    vec3d v;
    for (int i = 0; i < n; i++)
      v = v + vec3d(1,2,3); // constructor is not inline+pass by value
    return v.abs();
}

// add n vectors and return the magnitude using non-inline object
double test9(uint32_t n) {
    vec3d_inline v(3,5,2);
    for (int i = 0; i < n; i++)
      v = v + vec3d_inline(1,2,3); // this function is pass by value
    return v.abs();
}

int main(int argc, char* argv[]) {
  const uint32_t n = atoi(argv[1]);
  //test1(n);
  //test2(n);
  //test3(n);
  double ans = test8(n);
  //double ans = test9(n);
  cout << ans << '\n';
}