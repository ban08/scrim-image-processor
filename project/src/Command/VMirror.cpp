#include "Command/VMirror.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {

        // Construct a VMirror command
        VMirror::VMirror()
                : Command("v_mirror")
        {}

        // Apply vertical mirror: swap pixels top-to-bottom in each column
        Image* VMirror::apply(Image* img) {
            if (!img)
                return nullptr;  // nothing to do if image is null

            int w = img->width();
            int h = img->height();

            // For each column, swap pixels symmetrically around the horizontal center
            for (int x = 0; x < w; ++x) {
                for (int y = 0; y < h / 2; ++y) {
                    Color& top    = img->at(x, y);
                    Color& bottom = img->at(x, h - 1 - y);
                    std::swap(top, bottom);
                }
            }

            return img;
        }

    }
}
