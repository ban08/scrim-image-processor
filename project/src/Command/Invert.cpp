#include "Command/Invert.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {

        // Construct an Invert command
        Invert::Invert()
                : Command("invert")
        {}

        // Apply color inversion to each pixel in the image
        Image* Invert::apply(Image* img) {
            if (!img)
                return nullptr;  // nothing to do if image is null

            int w = img->width();
            int h = img->height();

            // For each pixel, set each channel to (255 - current)
            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    Color& c = img->at(x, y);
                    c.red()   = 255 - c.red();
                    c.green() = 255 - c.green();
                    c.blue()  = 255 - c.blue();
                }
            }

            return img;
        }

    }
}
