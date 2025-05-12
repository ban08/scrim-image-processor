#include "Command/Crop.hpp"
#include "Image.hpp"

namespace prog {
 namespace command{
    Crop::Crop(int x, int y, int w, int h)
        : Command("crop"), x_(x), y_(y), w_(w), h_(h) {}

    Image* Crop::apply(Image* img) {
        if (!img) return nullptr;
        Image* newImg = new Image(w_, h_); // Default fill is white
        int origW = img->width();
        int origH = img->height();
        for (int dy = 0; dy < h_; ++dy) {
            for (int dx = 0; dx < w_; ++dx) {
                int origX = x_ + dx;
                int origY = y_ + dy;
                if (origX >= 0 && origX < origW && origY >= 0 && origY < origH) {
                    newImg->at(dx, dy) = img->at(origX, origY);
                }
            }
        }
        delete img;
        return newImg;
    }
}
}