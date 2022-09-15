#ifndef STRING_BUFFER_HH
#define STRING_BUFFER_HH

#include <iostream>
#include "GrowArray.hh"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/unistd.h>
#include <fcntl.h>
#include "String.hh"
using namespace std;


class StringBuffer {
private:
  GrowArray<String> buffer;
  size_t initialSize;
  int cp;
  String& current(size_t estimateNeeded) {
    String& p = buffer.last();
    if (p.roomFor(estimateNeeded))
      return p;
    buffer.add(String());
    String& q = buffer.last();
    q.capacity(initialSize);
    return q;
  }
public:
  StringBuffer(size_t initialSize_, size_t blockSize_ = 16) : buffer(blockSize_, 0, (char*)0), initialSize(initialSize_) {
    cp = 0;
    buffer.add(String());
    buffer[0].capacity(initialSize);
  }
  StringBuffer& append(char v[])       { current(1).append(v); return *this; }
  StringBuffer& append(char v)         { current(1).append(v); return *this; }
  StringBuffer& append(int v)          { current(sizeof(int)*4).append(v); return *this; }
  StringBuffer& append(unsigned int v) { current(sizeof(unsigned int)*4).append(v); return *this; }
  StringBuffer& append(float v)        { current(sizeof(float)*3).append(v); return *this; }
  StringBuffer& append(double v)       { current(sizeof(double)*4).append(v); return *this; }
  StringBuffer& append(const char v[]) { current(256).append(v); return *this; }
  StringBuffer& append(const string& v) { current(256).append(v.c_str()); return *this; }
  StringBuffer& append(double v1, char sep, double v2) {
    current(sizeof(double)*4*2+1).append(v1, sep, v2);    return *this;
  }
  StringBuffer& append(double v1, char sep, double v2, char sep2, double v3) {
    current(sizeof(double)*4*3+2).append(v1, sep, v2).append(sep2).append(v3);    return *this;
  }
  StringBuffer& append(double v1, char sep, double v2, char sep2, double v3, char sep3, double v4) {
    current(sizeof(double)*4*4+3).append(v1, sep, v2).append(sep2).append(v3).append(sep3).append(v4);    return *this;
  }

  StringBuffer& append(double v1, const char sep[], double v2) {
    current(sizeof(double)*4*2+1).append(v1, sep, v2);    return *this;
  }
  StringBuffer& appendBrackets(const char openBracket[],
			       const double v[], int numElements, char sep, const char closeBracket[]) {
    append(openBracket);
    for (int i = 0; i < numElements; i++)
      append(v[i]).append(sep);
    append(closeBracket);
    return *this;
  }
  
  void readFile(string library) throw (char*) {
    int fh = open(library.c_str(), O_RDONLY);
    if (fh < 0) {
      throw "error opening postscript library file";
    }
    struct stat info;
    fstat(fh, &info);
    String& c = buffer.last();
    if (info.st_size > c.capacity()) {
      buffer.add(String());
      String& c = buffer.last();
      c.read(fh, info.st_size);
    } else {
      c.readAppend(fh, info.st_size);
    }
    close(fh);
	
    
  }

  StringBuffer& appendFormatted(const char fmt[], double v)       {
    current(32).appendFormatted(fmt, v); return *this;
  }
  StringBuffer& appendFormatted(const char fmt[], double v1, double v2) {
    current(32).appendFormatted(fmt, v1).appendFormatted(fmt, v2); return *this;
  }
  StringBuffer& appendFormatted(const char fmt[], double v1, double v2, double v3) {
    current(64).appendFormatted(fmt, v1).appendFormatted(fmt, v2).appendFormatted(fmt, v3); return *this;
  }

  template<typename T>
  StringBuffer& append(const T& obj) {
    obj.print(*this);
    return *this;
  }

  friend ostream& operator <<(ostream& s, const StringBuffer& b) {
    for (int i = 0; i < b.buffer.size(); i++)
      s << b.buffer[i];
    return s;
  }
};

#endif
