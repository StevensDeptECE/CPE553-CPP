#include <unistd.h>
#include <chrono>
#include <iostream>

class TimeMe {
  std::chrono::time_point<std::chrono::steady_clock> lastTime;
public:
  TimeMe() {
    lastTime = std::chrono::steady_clock::now();
  }
  bool timeToAnimate(uint64_t elapsed) {
    auto now = std::chrono::steady_clock::now();
    if ((now-lastTime).count() < elapsed)
      return false;
    std::cout << (now-lastTime).count() << '\n';
    lastTime = now;
    return true;
  }
  void update() {
    if (timeToAnimate(2000000000))
      std::cout << "update me\n"; //dosomething();
  }

};

int main() {
#if 0
  TimeMe t;
  for (int i = 0; i < 1000; i++) {
    t.update();
    usleep(100);

  }
  #endif
  auto t0 = std::chrono::steady_clock::now();
  for (int i = 0; i < 100000000; i++) {
    auto t = std::chrono::steady_clock::now();
  }
  auto t1 = std::chrono::steady_clock::now();
  std::cout << (t1-t0).count() << '\n';
}
