/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: Material.h
 *  Description: Simple ray-tracer written in C++.
 */

#ifndef MATERIAL_H
#define MATERIAL_H

#include "Vec3.h"
#include "Ray.h"
#include "Hittable.h"

struct HitRecord;

class Material {
public:
    virtual bool scatter(const Ray & ray_in, const HitRecord & record,
                         ColorRGB & attenuation, Ray & scattered) const = 0;
};

#endif // MATERIAL_H
