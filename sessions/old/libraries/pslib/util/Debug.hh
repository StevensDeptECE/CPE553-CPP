#ifndef DEBUG_HH
#define DEBUG_HH

#include <stdio.h>
#include <stdarg.h>

template<typename Stream>
class Debug {
private:
  int currentLevel;
  Stream& s;
  char buf[256];
public:
  Debug(Stream& s_, int level) : s(s_), currentLevel(level) {}
  void msg(int level, const char msg[]) {
    if (level <= currentLevel) { s << msg; }
  }
  void printf(int level, const char fmt[], ...) {
    if (level <= currentLevel) {
      va_list va;
      va_start(va, fmt);
      vsprintf(buf, fmt, va);
      s << buf;
    }
  }
  void setLevel(int level) { currentLevel = level; }
  int getLevel() const { return currentLevel; }
};
#endif
