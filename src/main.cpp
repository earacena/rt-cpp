/*
 *  Project: rt-cpp
 *  Author: earacena
 *  Filename: main.cpp
 *  Description: Simple ray-tracer written in C++.
 */

#include <iostream>
#include <string>
#include <cstdlib>

void print_usage() {
    std::cerr << "Usage:" << std::endl 
              << "\t./rt [width] [height]" << std::endl 
              << "\tArgs:" << std::endl
              << "\twidth: numeric value, 1-2000" << std::endl
              << "\theight: numeric value, 1-2000" << std::endl;
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
    // Iterate every pixel
    for (int row = image_height; row > 0; --row) {
        for(int col = 0; col < image_width; ++col) {
            std::cout << "100 100 10" << std::endl;
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
