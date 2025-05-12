#include "Command/Replace.hpp"
#include "Image.hpp"

namespace prog {
  namespace command{
    Replace::Replace(const Color& oldC, const Color& newC)
        : Command("replace"), oldColor(oldC), newColor(newC) {}

    Image* Replace::apply(Image* img) {
        if (!img) return nullptr;

        int w = img->width();
        int h = img->height();

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                Color& c = img->at(x, y);
                if (c.red() == oldColor.red() &&
                    c.green() == oldColor.green() &&
                    c.blue() == oldColor.blue()) {
                    c = newColor;
                }
            }
        }
        return img;
    }
}
}