/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: Material.h
 *  Description: Simple ray-tracer written in C++.
 */
#ifndef METAL_H
#define METAL_H

class Metal : public Material {
public:
    Metal(const ColorRGB & albedo) : albedo(albedo) { }

    virtual bool scatter(const Ray & ray_in, const HitRecord & record,
                         ColorRGB & attenuation, Ray & scattered) const override {
        Vec3 reflected = reflect(unit_vector(ray_in.direction()), record.normal);
        scattered = Ray(record.point, reflected);
        attenuation = albedo;
        return (dot(scattered.direction(), record.normal) > 0);
    }

  // Data members
  ColorRGB albedo;

};

#endif // METAL_H
