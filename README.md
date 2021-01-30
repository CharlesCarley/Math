# Math

Is a basic linear math library for 2D & 3D Graphics with OpenGL.

## Building with CMake & Make

```sh
mkdir build
cd build
cmake ..
make
```

### Optional defines

+ Math_SCALAR_DOUBLE - Define scalar type as double. Default:OFF (float)

### References

Some portions have been derived from:

+ Dunn, Fletcher. “3D Math Primer for Graphics and Game Development.” Amazon, CRC Press, 2012, http://www.amazon.com/Math-Primer-Graphics-Game-Development/dp/1568817231.
    + <b>Notably</b> portions of skEuler, skQuaternion, skMatrix3, skMatrix4 and skMath.
+   https://en.wikipedia.org/w/index.php?title=HSL_and_HSV&oldid=941280606
    +   HSV Reference
