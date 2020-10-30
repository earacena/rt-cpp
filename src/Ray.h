/*
 *  Project: rt-cpp
 *  Author: earacena
 * Filename: Ray.h
 * Description: Simple ray-tracer written in C++.
 */

#ifndef RAY_H
#define RAY_H

#include "Vec3.h"

class Ray {
public:
    Ray() { }

    Ray(const Point3 & origin, const Vec3 & direction) 
        : orig(origin), dir(direction) { }

    Point3 origin() const {
        return orig;
    }

    Vec3 direction() const {
        return dir;
    }

    Point3 at(double t) const {
        // r(t) = o + td 
        return orig + (t * dir);
    }
    
    // Data members
    Point3 orig;
    Vec3 dir;
};

#endif // RAY_H
