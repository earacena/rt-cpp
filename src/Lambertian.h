/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: Lambertian.h
 *  Description: Simple ray-tracer written in C++.
 */

#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "Material.h"

class Lambertian : public Material {
public:
    Lambertian(const ColorRGB & albedo) : albedo(albedo) { }

    virtual bool scatter(const Ray & ray_in, const HitRecord & record,
                         ColorRGB & attenuation, Ray & scattered) const override {
    
        auto scatter_direction = record.normal + random_unit_vector();
    
        // catch scatter direction close to zero
        if (scatter_direction.near_zero())
            scatter_direction = record.normal;

        scattered = Ray(record.point, scatter_direction);
        attenuation = albedo;
        return true;
    }

  // Data members
  ColorRGB albedo;

};

#endif // LAMBERTIAN_H
