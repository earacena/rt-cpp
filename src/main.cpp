/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: main.cpp
 *  Description: Simple ray-tracer written in C++.
 */

#include <iostream>
#include <string>
#include <cstdlib>

#include "Vec3.h"

void print_usage() {
    std::cerr << "Usage:" << std::endl 
              << "\t./rt [width] [height]" << std::endl 
              << "\tArgs:" << std::endl
              << "\twidth: numeric value, 1-2000" << std::endl
              << "\theight: numeric value, 1-2000" << std::endl;
}

void write_color(std::ostream & output, const ColorRGB color) {
    // RGB triplets follow arithmentic notation from 0-1,
    // convert to a color value from 0-255 and output
    output << static_cast<int>(255.999 * color.x()) << " "
           << static_cast<int>(255.999 * color.y()) << " "
           << static_cast<int>(255.999 * color.z()) << std::endl;
}

void render(const uint16_t image_width, const uint16_t image_height) {
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
    // Iterate every pixel, slowly fading in green values left to right,
    // and fading out red values top to bottom
    double r = 0.0;
    double g = 0.0;
    double b = 0.0;
    ColorRGB color = ColorRGB(0.0, 0.0, 0.0);
    for (int row = image_height-1; row >= 0; --row) {
        for(int col = 0; col < image_width; ++col) {
            r = static_cast<double>(col) / static_cast<double>(image_width-1);
            g = static_cast<double>(row) / static_cast<double>(image_height-1);
            b = static_cast<double>(row+col) / static_cast<double>(image_width+image_height-2);
            std::get<0>(color.e) = r;
            std::get<1>(color.e) = g;
            std::get<2>(color.e) = b;
            write_color(std::cout, color);
        }
    }

}

int main(int argc, char *argv[]) {
    // Check number of arguments
    if ((argc < 3) || (argc >= 4)) {
        std::cout << "[err] Incorrect number of arguments." << std::endl;
        print_usage();
        return 0;
    }
    
    // Convert arguments into image dimensions variables
    const uint16_t image_width = static_cast<uint16_t>(std::atoi(argv[1]));
    const uint16_t image_height = static_cast<uint16_t>(std::atoi(argv[2]));

    // Render
    render(image_width, image_height);    
        
    return 0;
}
