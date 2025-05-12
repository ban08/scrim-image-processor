#include "Command/Invert.hpp"
#include "Image.hpp"

namespace prog {
  namespace command{
    Invert::Invert() : Command("invert") {}

    Image* Invert::apply(Image* img) {
        if (!img) return nullptr;

        int w = img->width();
        int h = img->height();

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                Color& c = img->at(x, y);
                c.red() = 255 - c.red();
                c.green() = 255 - c.green();
                c.blue() = 255 - c.blue();
            }
        }
        return img;
    }
}
}