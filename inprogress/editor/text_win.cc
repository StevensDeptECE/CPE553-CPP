#include "text_win.hh"
#include <unistd.h>
#include <fcntl.h>

text_win::text_win() : cursor(0), s(cout) {
  //screen = 1;
}
