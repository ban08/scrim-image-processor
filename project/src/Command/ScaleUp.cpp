#include "Command/ScaleUp.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {

        // Construct a ScaleUp command:
        // - xScale, yScale: factors to multiply the width and height
        ScaleUp::ScaleUp(int xScale, int yScale)
                : Command("scaleup")
                , xScale_(xScale)
                , yScale_(yScale)
        {}

        // Apply upscaling to the image by nearest-neighbor
        Image* ScaleUp::apply(Image* img) {
            // Return original if invalid image or non-positive scale
            if (!img || xScale_ <= 0 || yScale_ <= 0)
                return img;

            int origW = img->width();
            int origH = img->height();
            int newW  = origW * xScale_;
            int newH  = origH * yScale_;

            // Create new image of scaled size (default fill color)
            Image* newImg = new Image(newW, newH);

            // Map each pixel in the new image back to the original
            for (int y = 0; y < newH; ++y) {
                for (int x = 0; x < newW; ++x) {
                    int origX = x / xScale_;
                    int origY = y / yScale_;
                    newImg->at(x, y) = img->at(origX, origY);
                }
            }

            delete img;
            return newImg;
        }

    }
}
