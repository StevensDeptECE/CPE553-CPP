#ifndef GROW_ARRAY_H
#define GROW_ARRAY_H

#include <iostream>
using namespace std;
#include <memory.h>

template<typename T>
class GrowArray {
private:
  T* data;
  int sz;
  int cap;
  void copy(const GrowArray& orig) {
    sz = orig.sz;
    cap = orig.cap;
    data = new T[cap];
    for (int i = 0; i < sz; i++)
      data[i] = orig.data[i];
  }

  void grow() {
    growToAtLeast(cap+cap);
  }

  void init(size_t initialCapacity, size_t initialSz, const T& v) {
    data = new T[initialCapacity];
    cap = initialCapacity;
    sz = initialSz;
    for (int i = 0; i < sz; i++)
      data[i] = v;
  }
  // write custom verion of delete[] so that elements of the array never initialized are not destructed
  void freemem() {
    cerr << "freeing list memory\n";
    for (int i = 0; i < sz; i++)
      data[i].~T();
    cerr << "about to free list block memory\n";
    delete [] (char*)data;
  }
public:
  GrowArray() {
    data = 0;
    sz = 0;
    cap = 0;
  }

  // reserve capacity of n elements, but zero used, uninitialized
  GrowArray(size_t initialCapacity) {
    data = (T*)new char[initialCapacity * sizeof(T)];
    sz = 0;
    cap = initialCapacity;
  }

  GrowArray(size_t initialCapacity, const T& v) {
    init(initialCapacity, initialCapacity, v);
  }

  GrowArray(size_t initialCapacity, size_t initialSz, const T& v) {
    init(initialCapacity, initialSz, v);
  }

  GrowArray(const T data_[], int n) {
    data = new T[n * sizeof(T)];
    cap = sz = n;
    for (int i = 0; i < n; i++)
      data[i] = data_[i];
  }

  GrowArray(const GrowArray& orig) {
    copy(orig);
  }

  GrowArray& operator =(const GrowArray& orig) {
    if (this == &orig) 
      return *this;
    freemem();
    copy(orig);
  }

  // copy for arrays of the same size
  void copyInPlace(const GrowArray& orig) {
    for (int i = 0; i < sz; i++)
      data[i] = orig.data[i];
  }

  ~GrowArray() {
    freemem();
  }

  void clear() {
    for (int i = 0; i < sz; i++)
      data[i].~T();
    sz = 0;
  }

  void growToAtLeast(int newSize) {
    if (newSize < cap) return;
    if (newSize == 0) {
      newSize = 2;
      data = (T*) new char[sizeof(T) * newSize];
    } else {
      T* temp = (T*) new char[sizeof(T) * newSize];
      memcpy(temp, data, sizeof(T)*sz);
      delete[] (char*)data;
      data = temp;
    }
    cap = newSize;
  }

  size_t size() const {
    return sz;
  }
  void size(size_t sz_) { sz = sz_; }

  unsigned int capacity() const { return cap; }

  //TODO? would be conveniently matlab-like... but not everything is numbers 
  //void add(const T& start, const T& step, const T& end);

  void add(const T& e) {
    growToAtLeast(sz+4);
    data[sz++] = e;
  }

  void add(const T& e1, const T& e2) {
    growToAtLeast(sz+4);
    data[sz++] = e1;
    data[sz++] = e2;
  }

  void add(const T& e1, const T& e2, const T& e3) {
    growToAtLeast(sz+4);
    data[sz++] = e1;
    data[sz++] = e2;
    data[sz++] = e3;
  }

  void add(const T& e1, const T& e2, const T& e3, const T& e4) {
    growToAtLeast(sz+8);
    data[sz++] = e1;
    data[sz++] = e2;
    data[sz++] = e3;
    data[sz++] = e4;
  }

  void add(const T elements[], int n) {
    growToAtLeast(sz+n);
    for (int i = 0; i < n; i++)
      data[sz++] = elements[i];
  }

  void erase(int pos, int n) {
    for (int i = pos; i < sz - n; i++)
      data[i] = data[i+n];
    sz -= n;
  }

  void insert(int pos, int n) {
    growToAtLeast(sz+n);
    for (int i = sz; i >= pos; i--)
      data[i] = data[i-n];
    sz += n;
  }

  void insert(int pos, const T& val, int n) {
    growToAtLeast(sz+n);
    for (int i = 0; i < n; i++, pos++)
      data[pos] = val;    
    sz += n;
  }

  // insert external array at point in this list
  void insert(int pos, double arr[], int n) {
    insert(pos, n);
    for (int i = 0; i < n; i++, pos++)
      data[i] = arr[pos];
  }

  void copyInsert(int pos, int n, int from) {
    growToAtLeast(sz + n);
    for (int i = sz - 1; i > pos+n; i--) {
      data[i+n] = data[i];
    }
    for (int i = pos; i < pos + n; i++, from++)
      data[i] = data[from];
  }

  T& operator [](int i) { return data[i]; }
  const T& operator [](int i) const { return data[i]; }

  template<typename Stream>
  friend Stream& operator <<(Stream& s, const GrowArray<T>& g) {
    if (g.sz > 0) {
      s << g[0];
    for (int i = 1; i < g.sz; i++)
      s << ' ' << g[i];
    }
    return s;
  }

  template<typename Functor>
  void foreach(Functor f) {
    for (int i = 0; i < sz; i++)
      f(data[i]);
  }
  T& first() { return data[0];      }
  T& last()  { return data[sz - 1]; }
};
    
      
#endif
