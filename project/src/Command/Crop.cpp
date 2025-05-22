#include "Command/Crop.hpp"
#include "Image.hpp"
namespace prog {
    namespace command {

        // Construct a Crop command:
        // - x, y: top-left corner of the crop rectangle
        // - w, h: width and height of the crop rectangle
        Crop::Crop(int x, int y, int w, int h)
                : Command("crop")
                , x_(x)
                , y_(y)
                , w_(w)
                , h_(h)
        {}

        // Apply cropping to the given image
        Image* Crop::apply(Image* img) {
            if (!img)
                return nullptr;                 // nothing to do if image is null

            // Create new image of the target crop size (default fill white)
            Image* newImg = new Image(w_, h_);
            int origW = img->width();
            int origH = img->height();

            // Copy pixels from the original within the crop rectangle
            for (int dy = 0; dy < h_; ++dy) {
                for (int dx = 0; dx < w_; ++dx) {
                    int origX = x_ + dx;
                    int origY = y_ + dy;
                    // Only copy if inside original bounds
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
