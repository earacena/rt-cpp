/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: HittableList.cpp
 *  Description: Simple ray-tracer written in C++.
 */

#include "HittableList.h"

bool HittableList::hit(const Ray & ray, double t_min, double t_max,
                       HitRecord & record) const {

    HitRecord tmp_record;
    bool hit_anything = false;
    double closest_so_far = t_max;

    for (const auto & object : objects) {
        // Update the hit record to the closest object hit
        if (object->hit(ray, t_min, closest_so_fat, tmp_record)) {
            hit_anything = true;
            closest_so_far = tmp_record.t;
            record = tmp_record;
        }   
    }

    return hit_anything;
}

