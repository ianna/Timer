#include "timer.h"
#include <chrono>

static std::chrono::time_point<std::chrono::high_resolution_clock> t_start;
static std::chrono::time_point<std::chrono::high_resolution_clock> t_end;
static bool timer_is_set = false;

extern "C" {

void start(void) {
  t_start = std::chrono::high_resolution_clock::now();
  timer_is_set = true;

  return;
}

float stop(void) {
  t_end = std::chrono::high_resolution_clock::now();

  float f_ms(0.0);
  if (timer_is_set) {
    timer_is_set = false;
    f_ms = std::chrono::duration<float, std::chrono::milliseconds::period>(t_end - t_start).count();
  }

  return f_ms;
}

}
