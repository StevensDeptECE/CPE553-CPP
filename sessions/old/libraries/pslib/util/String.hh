#ifndef STRING_HH
#define STRING_HH

#include <iostream>
using namespace std;
#include <memory.h>
#include <stdio.h>

// length based string for preallocation and indexing efficiency
class String {
private:
  size_t len;
  size_t cap;
  char* text;
  void copy(const String& orig) {
    cap = orig.cap;
    len = orig.len;
    text = new char[cap];
    memcpy(text, orig.text, len);
  }
public:
  String() : len(0), cap(0), text(NULL) {}
  String(size_t initialCap) : len(0), cap(initialCap), text(new char[initialCap]) {}
  String(const char t[]) {
    if (t == NULL) {
      cap = len = 0;
      text = NULL;
    } else {
      cap = len = strlen(t);
      text = new char[cap];
      memcpy(text, t, cap);
    }
  }
  String(const char t[], size_t initialLen) : len(initialLen), cap(initialLen), text(new char[initialLen]) {
    memcpy(text, t, len);
  }

  String(char t, size_t initialLen) : len(initialLen), cap(initialLen), text(new char[initialLen]) {
    memset(text, t, initialLen);
  }

#if 0
  String(const char t[], size_t copies) {
    int tlen = strlen(t);
    cap = len = tlen * copies;
    text = new char[cap];
    char* p = text;
    for (int i = 0; i < copies; i++, p += tlen) {
      memcpy(p, t, tlen);
    }
  }
#endif

  ~String() { delete [] text; }
  String(const String& orig) {
    copy(orig);
  }
  String& operator =(const String& orig) {
    if (this != &orig) {
      delete[] text;
      copy(orig);
    }
    return *this;
  }
  bool operator ==(const String& b) const {
    if (len != b.len) return false; // length does not match, definitely not equal
    for (int i = 0; i < len; i++) {
      if (text[i] != b.text[i])
	return false;
    }
    return true;
  }

  //TODO: this isn't quite right. Check lengths.
  bool operator <(const String& b) const {
    int minLen = min(len, b.len);
    for (int i = 0; i < minLen; i++) {
      if (text[i] < b.text[i])
	return true;
      else if (text[i] > b.text[i])
	return false;
    }
    return false;
  }

  void capacity(size_t c) {
    if (cap < c) {
      char* temp = text;
      text = new char[c];
      memcpy(text, temp, len);
      delete[] temp;
      cap = c;
    }
  }
  size_t length() const { return len; }
  size_t capacity() const { return cap; }
  bool roomFor(size_t additional) {
    return len + additional < cap;
  }

  void checkCapacity(size_t additional) {
    capacity(len + additional);
  }

  void shrinkToFit() {
    if (len < cap) {
      char* temp = text;
      text = new char[len];
      memcpy(text, temp, len);
      cap = len;
      delete[] temp;
    }
  }

  String& operator +=(const String& right) {
    checkCapacity(len + right.len);
    memcpy(text+len, right.text, right.len);
    len += right.len;
    return *this;
  }

  String& append(const char s[]) {
    int len = strlen(s);
    checkCapacity(len);
    memcpy(text+this->len, s, len);
    this->len += len;
    return *this;
  }
  String& append(char v) {
    checkCapacity(1);
    text[len++] = v;
    return *this;
  }
  String& append(int v) {
    char buf[16];
    sprintf(buf, "%d", v);
    return append(buf);
  }
  String& append(unsigned int v) {
    char buf[16];
    sprintf(buf, "%ud", v);
    return append(buf);
  }
  String& append(float v) {
    char buf[16];
    sprintf(buf, "%f", v);
    return append(buf);
  }
  String& append(double v) {
    char buf[16];
    sprintf(buf, "%lf", v);
    return append(buf);
  }
  String& append(double v1, char sep, double v2) {
    char buf[33];
    sprintf(buf, "%lf%c%lf", v1,sep,v2);
    return append(buf);
  }

  String& append(double v1, const char sep[], double v2) {
    char buf[64];
    sprintf(buf, "%lf%s%lf", v1,sep,v2);
    return append(buf);
  }

  //TODO: come up with a better buffering strategy than prayer!
  String& appendFormatted(const char fmt[], double v) {
    char buf[33];
    sprintf(buf, fmt, v);
    return append(buf);
  }

  void read(int fh, int len) {
    if (len > cap) {
      capacity(len);
    }
    ::read(fh, text, len);
  }

  void readAppend(int fh, int newlen) {
    if (newlen > cap-len) {
      capacity(len + newlen);
    }
    ::read(fh, text+len, newlen);
    len += newlen;
  }

  void tocstr(char buf[], int n) const {
    if (len+1 > n) throw "string too big";
    memcpy(buf, text, len);
    buf[len] = '\0'; // add nul for stinky old c routines
  }
  friend ostream& operator <<(ostream& s, const String& str) {
    for (int i = 0; i < str.len; i++)
      s << str.text[i]; //TODO: this is slow, improve
    return s;
  }
};

#endif

