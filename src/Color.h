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
#include "Sphere.h"

ColorRGB compute_ray_color(const Ray & ray) {
    // Hardcoded for testing
    const Point3 sphere_center = Point3(0.0, 0.0, -1.0);
    
    double t = hit_sphere(sphere_center, 0.5, ray);
    // Negative t-values are ignored since they indicate
    // intersection behind origin of ray/camera
    if (t > 0.0) {
        // Normal unit vector, length of 1, values range from -1 to 1
        // Make this unit vector by subtracting the sphere center C
        // from surface intersection point, ray extended to t-value,
        // then normalize
        Vec3 N = unit_vector(ray.at(t) - sphere_center);
        
        // Return a color based on normalized values
        return 0.5 * ColorRGB(N.x()+1.0, N.y()+1.0, N.z()+1.0);
    }

    Vec3 unit_direction  = unit_vector(ray.direction());
    // Produces a t value that is scaled to y-coordinate, ranges from -1 to 1
    // if ray is at center (0, 0, 0), direction of ray points -1 < y < 1
    // normalize it by adding 1 and dividing by two
    t = 0.5 * (unit_direction.y() + 1.0);
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
