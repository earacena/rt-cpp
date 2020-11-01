/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: Hittable.h
 *  Description: Simple ray-tracer written in C++.
 */

#ifndef HITTABLE_H
#define HITTABLE_H

#include "common.h"
#include "Vec3.h"
#include "Ray.h"

struct HitRecord {
    Point3 point;
    Vec3 normal;
    double t;
    bool front_face;

    inline void set_face_normal(const Ray & ray, const Vec3 & outward_normal) {
        // If dot product is positive, ray is inside otherwise outside
        // Always have normals point against ray
        front_face = (dot(ray.direction(), outward_normal) < 0.0);
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class Hittable {
public:
    virtual bool hit(const Ray & ray, double t_min, double t_max, 
                     HitRecord & record) const = 0;
};

#endif // HITTABLE_H
