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
