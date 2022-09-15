#ifndef PARSE_H
#define PARSE_H

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

inline static int expect(istream& s, char buffer[256], const char name[]) {
  s.getline(buffer, 256);
  int i = 0;
  while (isspace(i))
    i++;
  int len = strlen(name);
  if (strncmp(name, buffer+i, len)) {
    cerr << "expected token: " << name << " but found: " << buffer+i << "\n";
    throw "expected token";
  }
  i += len;
  return i;
}

inline double expectDouble(istream& s, const char name[]) {
  char buffer[256];
  int i = expect(s, buffer, name);
  char* p;
  double result = strtod(buffer+i, &p);
  if (p == buffer+i) {
    throw "format exception";
  }
  return result;
}

inline int expectDouble(istream& s, const char name[], double* vals, int maxNum) {
  char buffer[256];
  int i = expect(s, buffer, name);
  char* p = buffer + i;
  char* q;
  int parsedCount = 0;
  double result = strtod(p, &q);
  while (p != q) {
    cerr << "read: " << result << "\n";
    vals[parsedCount++] = result;
    p = q;
    result = strtod(p, &q);
  }
  return parsedCount;
}

inline int expectInt(istream& s, const char name[]) {
  char buffer[256];
  int i = expect(s, buffer, name);
  char* p;
  int result = strtol(buffer+i, &p, 10);
  if (p == buffer+i) {
    throw "format exception";
  }
  return result;
}

inline string expectRGB(istream& s, const char name[]) {
  char buffer[256];
  int i = expect(s, buffer, name);
  char* p;
  float r = strtof(buffer+i, &p);
  float g = strtof(p, &p);
  float b = strtof(p, &p);
  if (p == buffer+i) {
    throw "format exception";
  }
  return string(buffer+i);
}

inline string expectString(istream& s, const char name[]) {
  char buffer[256];
  int i = expect(s, buffer, name);
  char* p = buffer + i;
  while (isspace(*p))
    p++;
  return string(p);
}

inline string expectToken(istream& s, const char name[]) {
  char buffer[256];
  int i = expect(s, buffer, name);
  char* p = buffer + i;
  while (isspace(*p))
    p++;
  char* q = p;
  while (!isspace(*q))
    q++;
  *q = '\0';
  return string(p);
}

#endif
