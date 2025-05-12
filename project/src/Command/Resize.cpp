#include "Command/Resize.hpp"
#include "Image.hpp"

namespace prog {
  namespace command{
    Resize::Resize(int x, int y, int w, int h)
        : Command("resize"), x_(x), y_(y), w_(w), h_(h) {}

    Image* Resize::apply(Image* img) {
        if (!img) return nullptr;
        Image* newImg = new Image(w_, h_); // Fill with default (white)
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