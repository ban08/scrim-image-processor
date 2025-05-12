#include "Command/ToGrayScale.hpp"
#include "Image.hpp"

namespace prog {
  namespace command{
    ToGrayScale::ToGrayScale() : Command("to_gray_scale") {}

    Image* ToGrayScale::apply(Image* img) {
        if (!img) return nullptr;

        int w = img->width();
        int h = img->height();

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                Color& c = img->at(x, y);
                rgb_value avg = (c.red() + c.green() + c.blue()) / 3;
                c.red() = avg;
                c.green() = avg;
                c.blue() = avg;
            }
        }
        return img;
    }
}
}