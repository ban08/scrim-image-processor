#include "Command/Slide.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {

        // Construct a Slide command:
        // - dx, dy: horizontal and vertical shift amounts (with wrap-around)
        Slide::Slide(int dx, int dy)
                : Command("slide")
                , dx_(dx)
                , dy_(dy)
        {}

        // Apply cyclic shift to the image.
        // Pixels shifted off one edge reappear on the opposite edge.
        Image* Slide::apply(Image* img) {
            if (!img)
                return nullptr;  // nothing to do if image is null

            int w = img->width();
            int h = img->height();
            // Create a new image of the same size (default fill color)
            Image* newImg = new Image(w, h);

            // For each destination pixel, compute source coordinates with wrap-around
            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    // Use modulo for wrap-around, ensuring positive values
                    int srcX = (x - (dx_ % w) + w) % w;
                    int srcY = (y - (dy_ % h) + h) % h;
                    newImg->at(x, y) = img->at(srcX, srcY);
                }
            }

            delete img;
            return newImg;
        }

    }
}
