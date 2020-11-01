/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: Vec3.h
 *  Description: Simple ray-tracer written in C++.
 */
#ifndef VEC3_H
#define VEC3_H

#include <array>
#include <cmath>

#include "common.h"

class Vec3 {
public:
    Vec3() : e{0.0, 0.0, 0.0} {}
    Vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}


    // Access operators
    double x() const {
        return std::get<0>(e);
    }

    double y() const {
        return std::get<1>(e);
    }

    double z() const {
        return std::get<2>(e);
    }
    
    double operator[](int i) const {
        return e.at(i);
    }

    double& operator[](int i) {
        return e.at(i);
    }

    // Vector operations
    Vec3 operator-() const {
        return Vec3(-1 * std::get<0>(e), 
                    -1 * std::get<1>(e), 
                    -1 * std::get<2>(e) );
    }
    
    Vec3 & operator+=(const Vec3 & v) {
        std::get<0>(e) += std::get<0>(v.e);
        std::get<1>(e) += std::get<1>(v.e);
        std::get<2>(e) += std::get<2>(v.e);

        return *this;
    }

    Vec3 & operator*=(const double t) {
        std::get<0>(e) *= t;
        std::get<1>(e) *= t;
        std::get<2>(e) *= t;

        return *this;
    }

    Vec3 & operator/=(const double t) {
        std::get<0>(e) *= (1/t);
        std::get<1>(e) *= (1/t);
        std::get<2>(e) *= (1/t);

        return *this;
    }

    double length_squared() const {
        return (std::get<0>(e) * std::get<0>(e)) + 
               (std::get<1>(e) * std::get<1>(e)) + 
               (std::get<2>(e) * std::get<2>(e));
    }

    double length() const {
        return std::sqrt(length_squared());
    }

    inline static Vec3 random() {
        return Vec3(random_double(), random_double(), random_double());
    }

    inline static Vec3 random(double min, double max) {
        return Vec3(random_double(min, max), random_double(min, max), 
                    random_double(min, max));
    }
    
    // Data members
    std::array<double, 3> e;
};

// Inline utility functions/operators for vector operations
//inline std::ostream & operator<<(std::ostream & out, const Vec3 & v) {
//    return out << std::get<0>(v.e) << " " 
//               << std::get<1>(v.e) << " " 
//               << std::get<2>(v.e);
//}

inline Vec3 operator+(const Vec3 & u, const Vec3 & v) {
    return Vec3( std::get<0>(u.e) + std::get<0>(v.e),
                 std::get<1>(u.e) + std::get<1>(v.e),
                 std::get<2>(u.e) + std::get<2>(v.e));
}

inline Vec3 operator-(const Vec3 & u, const Vec3 & v) {
    return Vec3( std::get<0>(u.e) - std::get<0>(v.e),
                 std::get<1>(u.e) - std::get<1>(v.e),
                 std::get<2>(u.e) - std::get<2>(v.e));
}

inline Vec3 operator*(const double t, const Vec3 & v) {
    // Scalar multiplication
    return Vec3( t * std::get<0>(v.e),
                 t * std::get<1>(v.e),
                 t * std::get<2>(v.e));
}

inline Vec3 operator*(const Vec3 & v, const double t) {
    // Scalar multiplication
    return Vec3( std::get<0>(v.e) * t, 
                 std::get<1>(v.e) * t, 
                 std::get<2>(v.e) * t );
}

inline Vec3 operator*(const Vec3 & u, const Vec3 & v) {
    return Vec3( std::get<0>(u.e) * std::get<0>(v.e),
                 std::get<1>(u.e) * std::get<1>(v.e),
                 std::get<2>(u.e) * std::get<2>(v.e));
}

inline Vec3 operator/(const Vec3 & v, const double t) {
    return Vec3( std::get<0>(v.e) * (1/t),
                 std::get<1>(v.e) * (1/t),
                 std::get<2>(v.e) * (1/t) );
}

inline double dot(const Vec3 & u, const Vec3 & v) {
    return (std::get<0>(u.e) * std::get<0>(v.e)) +
           (std::get<1>(u.e) * std::get<1>(v.e)) +
           (std::get<2>(u.e) * std::get<2>(v.e));
}

inline Vec3 cross(const Vec3 & u, const Vec3 & v) {
    Vec3 p = Vec3( (std::get<1>(u.e) * std::get<2>(v.e)) - 
                    (std::get<2>(u.e) * std::get<1>(v.e)),
                   (std::get<2>(u.e)* std::get<0>(v.e)) -
                    (std::get<0>(u.e) * std::get<2>(v.e)),
                   (std::get<0>(u.e) * std::get<1>(v.e)) - 
                    (std::get<1>(u.e) * std::get<0>(v.e)) );

    return p;
}

inline Vec3 unit_vector(const Vec3 & v) {
    return v / v.length();
}


// Functions
Vec3 random_in_unit_sphere();


// Type aliases
using ColorRGB = Vec3;
using Point3 = Vec3;

#endif // VEC3_H
