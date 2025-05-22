#include "Command/HMirror.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {

        // Construct an HMirror command
        HMirror::HMirror()
                : Command("h_mirror")
        {}

        // Apply horizontal mirror: swap pixels left-to-right on each row
        Image* HMirror::apply(Image* img) {
            if (!img)
                return nullptr;  // nothing to do if image is null

            int w = img->width();
            int h = img->height();

            // For each row, swap pixels symmetrically around the center
            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w / 2; ++x) {
                    Color& left  = img->at(x, y);
                    Color& right = img->at(w - 1 - x, y);
                    std::swap(left, right);
                }
            }

            return img;
        }

    }
}
