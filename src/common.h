/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: common.h
 *  Description: Simple ray-tracer written in C++.
 */

#ifndef COMMON_H
#define COMMON_H

#include <cmath>
#include <limits>
#include <memory>
#include <random>

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;


// Utility functions
inline double degrees_to_radians(double degrees) {
    return degrees * (pi / 180.0);
}

inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double random_double(double min, double max) {
    static std::uniform_real_distribution<double> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double clamp(double x, double min, double max) {
    if (x < min)
        return min;
    else if (max < x)
        return max;
    else
        return x;
}

#endif // COMMON_H
