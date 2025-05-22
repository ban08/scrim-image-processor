#include "Command/Resize.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {

        // Construct a Resize command:
        // - x, y: top-left corner of the source region in the original image
        // - w, h: width and height of the output image
        Resize::Resize(int x, int y, int w, int h)
                : Command("resize")
                , x_(x)
                , y_(y)
                , w_(w)
                , h_(h)
        {}

        // Apply resizing by copying a sub-region of the original into a new image
        Image* Resize::apply(Image* img) {
            if (!img)
                return nullptr;               // nothing to do if image is null

            // Create a new image of the requested size (default fill color)
            Image* newImg = new Image(w_, h_);
            int origW = img->width();
            int origH = img->height();

            // Copy pixels from the original, offset by (x_, y_)
            for (int dy = 0; dy < h_; ++dy) {
                for (int dx = 0; dx < w_; ++dx) {
                    int origX = x_ + dx;
                    int origY = y_ + dy;
                    // Only copy if within the bounds of the original
                    if (origX >= 0 && origX < origW &&
                        origY >= 0 && origY < origH) {
                        newImg->at(dx, dy) = img->at(origX, origY);
                    }
                }
            }

            delete img;
            return newImg;
        }

    }
}
