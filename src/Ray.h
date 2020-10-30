/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: Ray.h
 *  Description: Simple ray-tracer written in C++.
 */

#ifndef RAY_H
#define RAY_H

#include "Vec3.h"

class Ray {
public:
    Ray() { }

    Ray(const Point3 & origin, const Vec3 & direction) 
        : origin(origin), direction(direction) { }

    Point3 origin() const {
        return origin;
    }

    Vec3 direction() const {
        return direction;
    }

    Point3 at(double t) const {
        // r(t) = o + td 
        return origin + (t * direction);
    }
    
    // Data members
    Point3 origin;
    Vec3 direction;
};

#endif // RAY_H
