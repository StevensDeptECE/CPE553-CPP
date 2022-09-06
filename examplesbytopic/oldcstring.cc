#include <cstring>

using namespace std;

int main() {
  const  char* a = "abc"; // terminated with NUL  ctrl-@

  char b[256];
  strcpy(b, a); // unsafe

  strncpy(b, a, sizeof(b)); // safe, can't overflow

}
