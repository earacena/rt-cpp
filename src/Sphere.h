/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: Sphere.h
 *  Description: Simple ray-tracer written in C++.
 */

#ifndef SPHERE_H
#define SPHERE_H

#include "Vec3.h"
#include "Ray.h"

double hit_sphere(const Point3 & center, double radius, const Ray & ray) {
    // Sphere equation: (p - c) dot (p - c) = r^2
    // Intersection:
    //      ((o + td) - c) dot ((o + td) - c) = r^2 
    //      t^2(d dot d) +  2(o - c)td + (o - c) dot (o - c) - r^2 = 0
    //            a              b                    c

    // Quadratic formula, using sphere intersection formula
    Vec3 diff_o_c = ray.origin() - center;
    double a = dot(ray.direction(), ray.direction());
    double b = 2.0 * dot(diff_o_c, ray.direction());
    double c = dot(diff_o_c, diff_o_c) - (radius * radius);
    double discriminant = (b*b) - (4*a*c);

    // d < 0, no intersection
    // d = 0, 1 intersection, surface
    // d > 0, 2 intersections
    if (discriminant < 0.0) {
        // if negetive discriminant, no intersection, 
        // give negetive t-value
        return -1.0;
    } else {
        // if intersections, give t-value >= 0
        return (-b - std::sqrt(discriminant)) / (2.0 * a);
    }
}

#endif // SPHERE_H
