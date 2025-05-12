#include "Command/RotateLeft.hpp"
#include "Image.hpp"

namespace prog {
  namespace command{
    RotateLeft::RotateLeft() : Command("rotate_left") {}

    Image* RotateLeft::apply(Image* img) {
        if (!img) return nullptr;
        int origW = img->width();
        int origH = img->height();
        Image* newImg = new Image(origH, origW);
        for (int y = 0; y < origH; ++y) {
            for (int x = 0; x < origW; ++x) {
                newImg->at(origH - 1 - y, x) = img->at(x, y);
            }
        }
        delete img;
        return newImg;
    }
}
}