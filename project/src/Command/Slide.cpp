#include "Command/Slide.hpp"
#include "Image.hpp"

namespace prog {
  namespace command{
    Slide::Slide(int dx, int dy) : Command("slide"), dx_(dx), dy_(dy) {}

    Image* Slide::apply(Image* img) {
        if (!img) return nullptr;
        int w = img->width();
        int h = img->height();
        Image* newImg = new Image(w, h);

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                int srcX = (x - dx_ % w + w) % w;
                int srcY = (y - dy_ % h + h) % h;
                newImg->at(x, y) = img->at(srcX, srcY);
            }
        }
        delete img;
        return newImg;
    }
}
}