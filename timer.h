// BSD 3-Clause License; see https://github.com/scikit-hep/awkward-1.0/blob/main/LICENSE

#ifndef AWKWARD_TIMER_H_
#define AWKWARD_TIMER_H_

#include <time.h>

#ifndef LIBAWKWARD_EXPORT_SYMBOL
  #define LIBAWKWARD_EXPORT_SYMBOL
#endif

extern "C" {
  LIBAWKWARD_EXPORT_SYMBOL void start_timer();
  LIBAWKWARD_EXPORT_SYMBOL void stop_timer();
}

#endif // AWKWARD_TIMER_H_
