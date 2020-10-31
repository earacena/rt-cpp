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
    //      t^2(d dot d) +  2(o - c) dot td + (o - c) dot (o - c) - r^2 = 0
    //            a              b                    c
    // Given that: 
    // b = 2 ((o - c) dot d)
    // b = 2h
    // (-b +- sqrt(b^2 - 4ac))/2a, Quadratic formula
    // becomes
    // (-h +- sqrt(h^2 - ac))/a, simplified formula
    
    Vec3 diff_o_c = ray.origin() - center;
    double a = dot(ray.direction(), ray.direction());
    double h = dot(diff_o_c, ray.direction());
    double c = dot(diff_o_c, diff_o_c) - (radius * radius);
    double discriminant = (h*h) - (a*c);

    // d < 0, no intersection
    // d = 0, 1 intersection, surface
    // d > 0, 2 intersections
    if (discriminant < 0.0) {
        // if negetive discriminant, no intersection, 
        // give negetive t-value
        return -1.0;
    } else {
        // if intersections, give t-value >= 0
        // using simplified formula
        return (-h - std::sqrt(discriminant)) / a;
    }
}

#endif // SPHERE_H
