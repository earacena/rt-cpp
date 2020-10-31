/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: Color.h
 *  Description: Simple ray-tracer written in C++.
 */

#ifndef COLOR_H
#define COLOR_H

#include <iostream>

#include "Vec3.h"
#include "Ray.h"

ColorRGB compute_ray_color(const Ray & ray) {
    Vec3 unit_direction  = unit_vector(ray.direction());
    double t = 0.5 * (unit_direction.y() + 1.0);
    return  (1.0 - t) * ColorRGB(0.1, 1.0, 0.1) + 
            t * ColorRGB(0.5, 0.7, 1.0);
}

void write_color(std::ostream & output, const ColorRGB color) {
    // RGB triplets follow arithmentic notation from 0-1,
    // convert to a color value from 0-255 and output
    output << static_cast<int>(255.999 * color.x()) << " "
           << static_cast<int>(255.999 * color.y()) << " "
           << static_cast<int>(255.999 * color.z()) << std::endl;
}


#endif // COLOR_H
