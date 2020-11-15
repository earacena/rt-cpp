# Ray Tracer

## Description

  A ray-tracer written in C++17.

### Features (implemented/WIP)
  * Objects
    * Spheres

  * Materials
    * Diffuse

  * Utility 
    * Saving render to .ppm file

  * Performance
    * Multithreading

## Usage

```
./rt [image width] [aspect width] [aspect height] [# of samples] [# of threads]
  Args:
  width: numeric value, example: 1600
  aspect width: numeric value, example: 16
  aspect height: numeric value, example: 9
  # of samples: numeric value, example: 100
  # of threads: numeric value, example: 4
```

### Requirements

```
g++, latest version or atleast supporting c++17  
Any *.ppm supporting image viewer
```

### Building

Use the included makefile:
```
make
```

### Running

To quickly try out a sample image, use the makefile recipe:
```
make run
```
This will generate a 1600x900 .ppm image with 12 anti-aliasing samples, using 4 threads to boost performance. Otherwise, follow the usage instructions to try different settings.

## References
[_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
