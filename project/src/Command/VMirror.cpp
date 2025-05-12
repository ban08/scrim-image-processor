#include "Command/VMirror.hpp"
#include "Image.hpp"

namespace prog {
  namespace command{
    VMirror::VMirror() : Command("v_mirror") {}

    Image* VMirror::apply(Image* img) {
        if (!img) return nullptr;
        int w = img->width();
        int h = img->height();
        for (int x = 0; x < w; ++x) {
            for (int y = 0; y < h/2; ++y) {
                Color& top = img->at(x, y);
                Color& bottom = img->at(x, h - 1 - y);
                std::swap(top, bottom);
            }
        }
        return img;
    }
}
}