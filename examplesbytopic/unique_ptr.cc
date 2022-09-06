#include <memory>
using namespace std;

int main() {
  const uint32_t n = 40000000;
  uint64_t*p = new uint64_t[n];
  for (int i = 0; i < n; i++)
    p[i] = i;

  unique_ptr<uint64_t> mem = make_unique<uint64_t>(n);

  uint64_t* p1 = mem.get();
  for (int i = 0; i < n; i++)
    p1[i] = i;

  uint64_t* p2 = (uint64_t*)((char*)mem.get() + 128832);
  
  for (int i = 0; i < n/2; i++)
    p2[i] = i;
  return 0;
}


  
