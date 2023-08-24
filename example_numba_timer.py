import ctypes
import numba

DSO = ctypes.CDLL('./libtimer.dylib')
c_func_start = DSO.start
c_func_stop = DSO.stop

c_func_start.restype = ctypes.c_uint
c_func_stop.restype = ctypes.c_uint

c_func_start.argtypes = []
c_func_stop.argtypes = []

@numba.njit
def example():
  c_func_start()
  for i in range(100_000_000_000):
    i = i**2
  t = c_func_stop()
  return t

example()
