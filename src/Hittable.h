/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: Hittable.h
 *  Description: Simple ray-tracer written in C++.
 */

#ifndef HITTABLE_H
#define HITTABLE_H

struct HitRecord {
    Point3 point;
    Vec3 normal;
    double t;
};

class Hittable {
public:
    virtual bool hit(const Ray & ray, double t_min, double t_max, 
                     HitRecord & record) const = 0;
};

#endif // HITTABLE_H
