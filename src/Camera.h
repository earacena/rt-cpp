/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: Camera.h
 *  Description: Simple ray-tracer written in C++.
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "Vec3.h"
#include "Ray.h"

class Camera {
public:

    Camera() { }
    Camera( const double viewport_height,
            const double aspect_ratio,
            const double focal_length,
            const Point3 & origin ) {
        
        this->viewport_width = aspect_ratio * viewport_height;
        this->viewport_height = viewport_height;
        this->origin = origin;

        this->horizontal = Vec3(viewport_width, 0.0, 0.0);
        this->vertical = Vec3(0.0, viewport_height, 0.0);
        this->lower_left = origin - (horizontal/2) - (vertical/2) - 
                          Vec3(0.0, 0.0, focal_length);
    }

    Ray calculate_ray(double u, double v) const {
        // Compute ray looking from camera to offsets u and v
        return Ray( origin, 
                    lower_left + (u * horizontal) + (v * vertical) - origin);
    }

    // Data members
    double viewport_width;
    double viewport_height;

    Point3 origin;      // indicates camera position
    Vec3 horizontal;    // indicates where left and right is
    Vec3 vertical;      // indicates where up and down is
    Vec3 lower_left;    // indicates lower left corner of viewport
};

#endif // CAMERA_H


