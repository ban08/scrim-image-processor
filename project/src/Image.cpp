#include "Image.hpp"

namespace prog {
    // Constructor: Initialize dimensions and fill pixels with given color
    Image::Image(int w, int h, const Color &fill)
     : width_(w), height_(h), pixels_(h, std::vector<Color>(w,fill)) {}
    // Destructor
    Image::~Image() = default;
    //getters
    int Image::width() const {
        return width_;
    }

    int Image::height() const {
        return height_;
    }

    // Mutable pixel access (y is row, x is column)
    Color &Image::at(int x, int y) {
		return pixels_[y][x];  // Directly return reference to pixel (x,y)
    }
    // Read-only pixel access
    const Color &Image::at(int x, int y) const {
        return pixels_[y][x];
    }
}
