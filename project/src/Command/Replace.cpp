#include "Command/Replace.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {

        // Construct a Replace command:
        // - oldC: color to be replaced
        // - newC: replacement color
        Replace::Replace(const Color& oldC, const Color& newC)
                : Command("replace")
                , oldColor(oldC)
                , newColor(newC)
        {}

        // Replace all pixels matching oldColor with newColor
        Image* Replace::apply(Image* img) {
            if (!img)
                return nullptr;  // nothing to do if image is null

            int w = img->width();
            int h = img->height();

            // Iterate over every pixel
            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    Color& c = img->at(x, y);
                    // If pixel matches oldColor, update it
                    if (c.red()   == oldColor.red() &&
                        c.green() == oldColor.green() &&
                        c.blue()  == oldColor.blue()) {
                        c = newColor;
                    }
                }
            }
            return img;
        }

    }
}
