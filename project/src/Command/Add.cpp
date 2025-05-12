#include "Command/Add.hpp"
#include "Image.hpp"
#include "PNG.hpp"

namespace prog {
  namespace command{
    Add::Add(const std::string& filename, const Color& neutral, int x, int y)
        : Command("add"), filename_(filename), neutral_(neutral), x_(x), y_(y) {}

    Image* Add::apply(Image* img) {
        if (!img) return nullptr;
        Image* overlay = loadFromPNG(filename_);
        if (!overlay) return img;

        int imgW = img->width();
        int imgH = img->height();
        int ovW = overlay->width();
        int ovH = overlay->height();

        for (int oy = 0; oy < ovH; ++oy) {
            int destY = y_ + oy;
            if (destY < 0 || destY >= imgH) continue;

            for (int ox = 0; ox < ovW; ++ox) {
                int destX = x_ + ox;
                if (destX < 0 || destX >= imgW) continue;

                const Color& src = overlay->at(ox, oy);
                if (src.red() != neutral_.red() ||
                    src.green() != neutral_.green() ||
                    src.blue() != neutral_.blue()) {
                    img->at(destX, destY) = src;
                }
            }
        }
        delete overlay;
        return img;
    }
}
}