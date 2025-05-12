#include "Command/Fill.hpp"
#include "Image.hpp"

namespace prog {
  namespace command{
    Fill::Fill(int x, int y, int w, int h, const Color& c)
        : Command("fill"), x_(x), y_(y), w_(w), h_(h), color_(c) {}

    Image* Fill::apply(Image* img) {
        if (!img) return nullptr;
        int imgW = img->width();
        int imgH = img->height();
        for (int y = y_; y < y_ + h_ && y < imgH; ++y) {
            if (y < 0) continue;
            for (int x = x_; x < x_ + w_ && x < imgW; ++x) {
                if (x < 0) continue;
                img->at(x, y) = color_;
            }
        }
        return img;
    }
}
}