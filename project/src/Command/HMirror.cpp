#include "Command/HMirror.hpp"
#include "Image.hpp"

namespace prog {
  namespace command{
    HMirror::HMirror() : Command("h_mirror") {}

    Image* HMirror::apply(Image* img) {
        if (!img) return nullptr;
        int w = img->width();
        int h = img->height();
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w/2; ++x) {
                Color& left = img->at(x, y);
                Color& right = img->at(w - 1 - x, y);
                std::swap(left, right);
            }
        }
        return img;
    }
}
}