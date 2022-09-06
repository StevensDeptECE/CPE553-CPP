#include <iostream>
#include <fstream>

string readFile(const char filename[]) {
  ifstream f(filename);
  f.seekg(0, std::ios::end);    // go to the end
  uint32_t length = t.tellg();  // report location (this is the length)
  f.seekg(0, std::ios::beg);    // go back to the beginning
  char* buffer = new char[length];    // allocate memory for a buffer of appropriate dimension
  f.read(buffer, length);       // read the whole file into the buffer
  string s(buffer);
  delete [] buffer;
  return s;
}
