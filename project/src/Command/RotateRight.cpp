#include "Command/RotateRight.hpp"
#include "Image.hpp"

namespace prog {
  namespace command{
    RotateRight::RotateRight() : Command("rotate_right") {}

    Image* RotateRight::apply(Image* img) {
        if (!img) return nullptr;
        int origW = img->width();
        int origH = img->height();
        Image* newImg = new Image(origH, origW);

        for (int y = 0; y < origH; ++y) {
            for (int x = 0; x < origW; ++x) {
                newImg->at(y, origW - 1 - x) = img->at(x, y);
            }
        }
        delete img;
        return newImg;
    }
}
}