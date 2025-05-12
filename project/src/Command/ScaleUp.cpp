#include "Command/ScaleUp.hpp"
#include "Image.hpp"

namespace prog {
  namespace command {
    ScaleUp::ScaleUp(int xScale, int yScale)
        : Command("scaleup"), xScale_(xScale), yScale_(yScale) {}

    Image* ScaleUp::apply(Image* img) {
        if (!img || xScale_ <= 0 || yScale_ <= 0) return img;
        int origW = img->width();
        int origH = img->height();
        int newW = origW * xScale_;
        int newH = origH * yScale_;
        Image* newImg = new Image(newW, newH);
        for (int y = 0; y < newH; ++y) {
            for (int x = 0; x < newW; ++x) {
                int origX = x / xScale_;
                int origY = y / yScale_;
                newImg->at(x, y) = img->at(origX, origY);
            }
        }
        delete img;
        return newImg;
    }
}
}