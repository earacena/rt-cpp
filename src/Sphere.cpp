/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: Sphere.cpp
 *  Description: Simple ray-tracer written in C++.
 */

#include "Sphere.h"

bool Sphere::hit( const Ray & ray, double t_min, double t_max, 
                  HitRecord & record ) const {

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
    if (discriminant > 0.0) {
        double root = std::sqrt(discriminant);

        double minus_root = (-h - root) / a;
        if (t_min < minus_root && minus_root < t_max) {
            record.t = minus_root;
            record.point = ray.at(record.t);
            Vec3 outward_normal = (record.point - center) / radius;
            record.set_face_normal(ray, outward_normal);
            return true;
        }

        double plus_root = (-h + root) / a;
        if (t_min < plus_root && plus_root < t_max) {
            record.t = plus_root;
            record.point = ray.at(record.t);
            Vec3 outward_normal = (record.point - center) / radius;
            record.set_face_normal(ray, outward_normal);
            return true;
        }
        
    }
    
    return false;
}
