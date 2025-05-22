#include "Command/Move.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {

        // Construct a Move command:
        // - dx, dy: horizontal and vertical shift amounts
        Move::Move(int dx, int dy)
                : Command("move")
                , dx_(dx)
                , dy_(dy)
        {}

        // Apply the shift to the image.
        // Pixels moved outside the bounds are discarded, and empty areas are left as default fill.
        Image* Move::apply(Image* img) {
            if (!img || dx_ < 0 || dy_ < 0)
                return img;                // nothing to do if image is null or negative shift

            int w = img->width();
            int h = img->height();
            // Create a new blank image of the same size (default fill color)
            Image* newImg = new Image(w, h);

            // For each pixel in the destination...
            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    // Compute source coordinates by subtracting the shift
                    int srcX = x - dx_;
                    int srcY = y - dy_;
                    // If the source pixel is within the original image, copy it
                    if (srcX >= 0 && srcX < w &&
                        srcY >= 0 && srcY < h) {
                        newImg->at(x, y) = img->at(srcX, srcY);
                    }
                    // Otherwise, leave the pixel at its default fill color
                }
            }

            delete img;
            return newImg;
        }

    }
}
