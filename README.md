# Timer

Build a libray on MacOS as follows:
```
g++ -c timer.cc
g++ -dynamiclib -current_version 1.0  timer.o  -o libtimer.dylib
```

Use it from Python:
```python
In [1]: import ctypes

In [2]: libtimer = ctypes.cdll.LoadLibrary("libtimer.dylib")

In [3]: def test():
   ...:     libtimer.start()
   ...:     for i in range(1000):
   ...:         i = i**2
   ...: 
   ...:     libtimer.stop()

In [4]: test()
CPU time used: 0.39ms
Wall clock time passed: 0.38

```
# Using the timer in Numba JIT-ed function

```python
In [1]: from numba import njit
   ...: from numba.core import types, typing
   ...: from llvmlite import binding
   ...: import os

In [2]: import ctypes

In [3]: DSO = ctypes.CDLL('./libtimer.dylib')

In [4]: c_func_start = DSO.start

In [5]: c_func_stop = DSO.stop

In [6]: import numba

In [7]: c_func_start.restype = ctypes.c_uint

In [8]: c_func_stop.restype = ctypes.c_uint

In [9]: c_func_start.argtypes = []

In [10]: c_func_stop.argtypes = []

In [11]: @njit
    ...: def example():
    ...:     c_func_start()
    ...:     c_func_stop()
    ...:     return
    ...: 

In [12]: example()
CPU time used: 0.01 ms
Wall clock time passed: 0.00

```
