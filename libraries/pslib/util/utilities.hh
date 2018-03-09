#ifndef UTIL_UTILITIES_H
#define UTIL_UTILITIES_H

#include <cmath>
#include <iostream>
#include "Debug.hh"
using namespace std;

namespace util {
  template<typename T>
  inline T square(T x) { return x*x; }

  template<typename T>
  inline T cube(T x) { return x*x*x; }

  template<typename T>
  inline T sumsq(const T& x, const T& y, const T& z) { return x*x + y*y + z*z; }

  template<typename T>
  inline T sumsq(const T& x, const T& y) { return x*x + y*y; }

  template<typename T>
  inline T rootsumsq(const T& x, const T& y, const T& z) {
    return sqrt(x*x + y*y + z*z);
  }
  
  template<typename T>
  inline bool boundedBy(const T& x, const T& a, const T& b) {
    return x >= a && x <= b;
  }

  template<typename T>
  inline bool boundedByPlusMinus(const T& x, const T& a, const T& b) {
    return x >= a-b && x <= a+b;
  }

  template<typename T>
  inline T min(const T& x, const T& y) { return x < y ? x : y; }

  template<typename T>
  inline T max(const T& x, const T& y) { return x > y ? x : y; }

template<typename T>
void minmax(const T x[], int n, T& minVal, T&maxVal) {
  minVal = maxVal = x[0];
  for (int i = 1; i < n; i++)
    if (x[i] < minVal) minVal = x[i];
    else if (x[i] > maxVal) maxVal = x[i];
}

template<typename T>
void minmax(const T& x, const T& y, T& min, T& max) {
  if (x < y) {
    min = x; max = y;
  } else {
    max = x; min = y;
  }
}

  //hyperefficient, but needs more testing.
  //TODO: fix test for last element
#if 0
template<typename T>
void minmax(const T x[], int n, T& minVal, T&maxVal) {
  if (n == 1) {
    minVal = maxVal = x[0];
    return;
  } else if (n == 0) {
    return;
  }
  if (x[0] < x[1]) {
    minVal = x[0];
    maxVal = x[1];
  } else {
    minVal = x[0];
    maxVal = x[1];
  }
  for (int i = 2; i < n; i += 2)
    if (x[i] < x[i+1]) {
      if (x[i] < minVal) minVal = x[i];
      if (x[i+1] > maxVal) maxVal = x[i+1];
    } else {
      if (x[i] > maxVal) maxVal = x[i];
      if (x[i+1] < minVal) minVal = x[i+1];
    }
}
#endif

template<typename T>
void minmax(const T x[], int n, const T& min, const T& max, T& minVal, T&maxVal) {
  if (n == 0) {
    return;
  }
  minVal = max;
  maxVal = min;
  for (int i = 0; i < n; i += 2) {
    if (x[i] < minVal && x[i] >= min) minVal = x[i];
    else if (x[i] > maxVal && x[i] <= max) maxVal = x[i];
  }
}

template<typename T>
T min(const T x[], int n) {
  T minVal = x[0];
  for (int i = 1; i < n; i++)
    if (x[i] < minVal) minVal = x[i];
  return minVal;
}

#if 0
  template<typename T>
  void minmax(const T x[], int n, T& minVal, T& maxVal);

  template<typename T>
  T min(const T x[], int n);
#endif
};

namespace pathplan {

  const double BIG = 1e8; // standardized cost for actions which are illegal and therefore super-expensive
  const double UGLY = BIG*BIG; // standardized cost for activity which is even worse than big.
  //  Debug<ostream> debug(cout, 2);
  const double gravity = 9.81;
  const double degreesToMeters = 60 * 1855;
  const double PI = 3.14159265358979;
  const double PI2 = PI * 2;
  const double TO_RAD = PI / 180;
  inline double costBounded(double val, double min, double max) {
    if (val < min) return BIG + (min - val) * UGLY;
    if (val > max) return BIG + (val - max) * UGLY;
    return 0;
  }

  inline double clampBounds(double val, double min, double max) {
    if (val < min) return min;
    if (val > max) return max;
    return val;
  }
};

extern Debug<ostream> debug;
#endif
