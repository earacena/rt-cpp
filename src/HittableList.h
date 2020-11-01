/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: HittableList.h
 *  Description: Simple ray-tracer written in C++.
 */

#ifndef HITTABLELIST_H
#define HITTABLELIST_H

#include <memory>
#include <vector>

#include "Ray.h"
#include "Hittable.h"

class HittableList : public Hittable {
public:

    HittableList() { }
    HittableList(std::shared_ptr<Hittable> object) {
        add(object);
    }

    void clear() {
        objects.clear();
    }

    void add(std::shared_ptr<Hittable> object) {
        objects.push_back(object);
    }

    virtual bool hit(const Ray & ray, double t_min, double t_max,
                      HitRecord & record) const override;

    // Data members
    std::vector<std::shared_ptr<Hittable>> objects;

};

#endif // HITTABLELIST_H

