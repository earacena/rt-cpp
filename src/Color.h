/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: Color.h
 *  Description: Simple ray-tracer written in C++.
 */

#ifndef COLOR_H
#define COLOR_H

#include <iostream>

#include "common.h"
#include "Sphere.h"
#include "HittableList.h"

ColorRGB compute_ray_color(const Ray & ray, const Hittable & world) {

    HitRecord record;
    // Iterated though all potentially hit objects and check for closest,
    // then use the closest surface normal for color
    if (world.hit(ray, 0.0, infinity, record)) 
        return 0.5 * (record.normal + ColorRGB(1.0, 1.0, 1.0));

    Vec3 unit_direction  = unit_vector(ray.direction());
    // Produces a t value that is scaled to y-coordinate, ranges from -1 to 1
    // if ray is at center (0, 0, 0), direction of ray points -1 < y < 1
    // normalize it by adding 1 and dividing by two
    double t = 0.5 * (unit_direction.y() + 1.0);
    return  (1.0 - t) * ColorRGB(0.7, 0.1, 0.5) + 
            t * ColorRGB(0.0, 0.0, 0.0);
}

void write_color(std::ostream & output, const ColorRGB color) {
    // RGB triplets follow arithmentic notation from 0-1,
    // convert to a color value from 0-255 and output
    output << static_cast<int>(255.999 * color.x()) << " "
           << static_cast<int>(255.999 * color.y()) << " "
           << static_cast<int>(255.999 * color.z()) << std::endl;
}


#endif // COLOR_H
