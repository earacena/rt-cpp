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

class Lambertian : public Material {
public:
    Lambertian(const ColorRGB & albedo) : albedo(albedo) { }

    virtual bool scatter(const Ray & ray_in, const HitRecord & record,
                         ColorRGB & attenuation, Ray & scattered) const override {
    
        auto scatter_direction. record.normal + random_unit_vector();
    
        // catch scatter direction close to zero
        if (scatter_direction.near_zero())
            scatter_direction = record.normal;

        scattered = Ray(record.p, scatter_direction);
        attenuation = albedo;
        return true;
    }

  // Data members
  ColorRGB albedo;

};

#endif // MATERIAL_H
