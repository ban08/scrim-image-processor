#include "Command/Move.hpp"
#include "Image.hpp"

namespace prog {
  namespace command{
    Move::Move(int dx, int dy) : Command("move"), dx_(dx), dy_(dy) {}

    Image* Move::apply(Image* img) {
        if (!img || dx_ < 0 || dy_ < 0) return img;
        int w = img->width();
        int h = img->height();
        Image* newImg = new Image(w, h);

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                int srcX = x - dx_;
                int srcY = y - dy_;
                if (srcX >= 0 && srcX < w && srcY >= 0 && srcY < h) {
                    newImg->at(x, y) = img->at(srcX, srcY);
                }
            }
        }
        delete img;
        return newImg;
    }
}
}