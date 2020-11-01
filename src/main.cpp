/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: main.cpp
 *  Description: Simple ray-tracer written in C++.
 */

#include <iostream>
#include <string>
#include <cstdlib>

#include "common.h"
#include "Camera.h"
#include "Color.h"

void print_usage() {
    std::cerr << "Usage:" << std::endl 
              << "./rt [image width] [aspect width] [aspect height]" << std::endl 
              << "\tArgs:" << std::endl
              << "\twidth: numeric value, example: 1600" << std::endl
              << "\taspect width: numeric value, example: 16" << std::endl
              << "\taspect height: numeric value, example: 9" << std::endl;
}

void render(const Camera & camera, const int image_width, 
            const int image_height) {
    // Generate a .ppm (Netpbm) image
    // P3 means RGB color image in ASCII
    std::cout << "P3" << std::endl;

    // Add image dimensions
    std::cout << image_width << " " << image_height << std::endl;
    
    // Max color value
    std::cout << "255" << std::endl;

    // Image data
    // every line is a RGB triplet
    // col is image_width pixels
    // row is image_height pixels
    
    double u = 0.0;     // 0.0-1.0 horizontal scale
    double v = 0.0;     // 0.0-1.0 horizontal scale
    
    ColorRGB color = ColorRGB(0.0, 0.0, 0.0);
    
    for (int row = image_height-1; row >= 0; --row) {
        std::cerr << "\rScanlines remaining: " << row << std::flush;
        for(int col = 0; col < image_width; ++col) {
            u = static_cast<double>(col) / static_cast<double>(image_width-1);
            v = static_cast<double>(row) / static_cast<double>(image_height-1);

            color = compute_ray_color(camera.calculate_ray(u, v)); 
            
            write_color(std::cout, color);
        }
    }
    std::cerr << std::endl << "Done rendering." << std::endl;
}

int main(int argc, char *argv[]) {
    // Check number of arguments
    if ((argc < 4) || (argc >= 5)) {
        std::cout << "[err] Incorrect number of arguments." << std::endl;
        print_usage();
        return 0;
    }
   
    // Image 
    // Convert arguments into image dimensions    
    const int image_width = static_cast<int>(std::atoi(argv[1]));
    double aspect_width = static_cast<double>(std::atoi(argv[2]));
    double aspect_height = static_cast<double>(std::atoi(argv[3]));
    const double aspect_ratio = aspect_width / aspect_height;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    // Camera
    Camera camera(2.0, aspect_ratio, 1.0, Point3(0.0, 0.0, 0.0));

    // Render
    render(camera, image_width, image_height);    
        
    return 0;
}
