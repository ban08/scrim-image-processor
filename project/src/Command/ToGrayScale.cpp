#include "Command/ToGrayScale.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {

        // Construct a ToGrayScale command
        ToGrayScale::ToGrayScale()
                : Command("to_gray_scale")
        {}

        // Convert each pixel to grayscale by averaging its RGB channels
        Image* ToGrayScale::apply(Image* img) {
            if (!img)
                return nullptr;  // nothing to do if image is null

            int w = img->width();
            int h = img->height();

            // For each pixel, compute the average of red, green, and blue
            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    Color& c = img->at(x, y);
                    rgb_value avg = (c.red() + c.green() + c.blue()) / 3;
                    c.red()   = avg;
                    c.green() = avg;
                    c.blue()  = avg;
                }
            }

            return img;
        }

    }
}
