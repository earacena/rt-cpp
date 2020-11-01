/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: Vec3.cpp
 *  Description: Simple ray-tracer written in C++.
 */

#include "Vec3.h"

Vec3 random_in_unit_sphere() {
    Vec3 point;
    // Pick random point inside unit sphere S
    // if the hit point is p and the normal to the sphere is N, 
    // (P-N) is considered the inside of the surface
    // (P+N) is considered the outside of the surface
    // Pick a random point inside the unit radius sphere on the same
    // side as the ray
    while (true) {
        point = Vec3::random(-1, 1);

        // Looking at the surface and a hit point p, if the random point
        // has a dot product of one or greater then it is "flat" against 
        // surface or pointing into surface, and not in unit sphere, 
        // if dot product is less than 1 then it it has a positive angle 
        // pointing into unit sphere.
        // Only return a randomized point pointing into unit sphere.
        if (point.length_squared() < 1)
            return point;
    }
}
