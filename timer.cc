#include "timer.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <ratio>

static std::chrono::time_point<std::chrono::high_resolution_clock> t_start;
static std::chrono::time_point<std::chrono::high_resolution_clock> t_end;

class MyTimer {
public:

  MyTimer()
  : _c_start(std::clock()) {
    t_start = std::chrono::high_resolution_clock::now();
  }

  ~MyTimer() {
    _c_end = std::clock();
    t_end = std::chrono::high_resolution_clock::now();
    float f_ms = std::chrono::duration<float, std::chrono::milliseconds::period>(t_end - t_start).count();

    std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
              << 1000.0 * (_c_end - _c_start) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              <<  f_ms << '\n';
  }

private:
  std::clock_t _c_start;
  std::clock_t _c_end;
};

static MyTimer* my_timer = nullptr;

extern "C" {

void start() {
  my_timer = new MyTimer();
}

void stop() {
  if (my_timer)
    delete my_timer;
}

}
