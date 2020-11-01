/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: Sphere.h
 *  Description: Simple ray-tracer written in C++.
 */

#ifndef SPHERE_H
#define SPHERE_H

#include "common.h"
#include "Hittable.h"

class Sphere : public Hittable {
public:
    Sphere() { }
    Sphere(const Point3 & center, double radius) 
        : center(center), radius(radius) { };

    virtual bool hit( const Ray & ray, double t_min, double t_max, 
                      HitRecord & record ) const override;

    // Data Members
    Point3 center;
    double radius; 
};

#endif // SPHERE_H
