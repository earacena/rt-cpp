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
#include "Vec3.h"
#include "Ray.h"
#include "Sphere.h"
#include "HittableList.h"

ColorRGB compute_ray_color(const Ray & ray, const Hittable & world, int depth) {

    // To avoid overflowing stack with recursion calls using the method below,
    // return no color/light after reaching a certain depth
    if (depth <= 0)
        return ColorRGB(0.0, 0.0, 0.0);

    HitRecord record;
    // Iterated though all potentially hit objects and check for closest,
    // then use the closest surface normal for color
    // A random point will send a ray thats within the unit sphere of the surface
    // out and recursively hit and recompute color until it fails to hit anything
    // Make t min avoid any hits very close to zero to avoid shadow acne
    if (world.hit(ray, 0.001, infinity, record)) { 
        Point3 target = record.point + record.normal + random_in_unit_sphere();
        return 0.5 * compute_ray_color( Ray(record.point, target - record.point), 
                                        world, 
                                        depth-1);

        Ray scattered;
        ColorRGB attenuation;
        if (record.mat_ptr->scatter(ray, record, attenuation, scattered))
            return attentuation + ray_color(scattered, world, depth-1);
        return ColorRGB(0.0, 0.0, 0.0);
    }

    Vec3 unit_direction  = unit_vector(ray.direction());
    // Produces a t value that is scaled to y-coordinate, ranges from -1 to 1
    // if ray is at center (0, 0, 0), direction of ray points -1 < y < 1
    // normalize it by adding 1 and dividing by two
    double t = 0.5 * (unit_direction.y() + 1.0);
    return  (1.0 - t) * ColorRGB(1.0, 1.0, 1.0) + 
            t * ColorRGB(0.5, 0.7, 1.0);
}

void write_color(std::ostream & output, const ColorRGB color, 
                 const int num_of_samples) {
    
    double r = color.x();
    double g = color.y();
    double b = color.z();

    // Divide the color by the number of pixel samples and gamma corrected for 
    // gamma=2.0 (sqrt is same as 1/2 where gamma is 1/gamma)
    double scale = 1.0 / num_of_samples;
    r = std::sqrt(scale * r);
    g = std::sqrt(scale * g);
    b = std::sqrt(scale * b);

    // RGB triplets follow arithmentic notation from 0-1,
    // convert to a color value from 0-255 and output
    output << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << " "
           << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << " "
           << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << std::endl;
}


#endif // COLOR_H
