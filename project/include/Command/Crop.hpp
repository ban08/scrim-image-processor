#ifndef CROP_HPP
#define CROP_HPP

#include "../Command.hpp"
#include "../Color.hpp"

namespace prog {
    namespace command {

/**
 * Crop command: extracts a rectangular region from an image.
 * The region is defined by its top-left corner (x_, y_) and size (w_ × h_).
 */
        class Crop : public Command {
            int x_, y_, w_, h_;  ///< crop rectangle: x, y, width, height

        public:
            /**
             * @param x  X-coordinate of the top-left corner of the crop rectangle.
             * @param y  Y-coordinate of the top-left corner of the crop rectangle.
             * @param w  Width of the crop rectangle.
             * @param h  Height of the crop rectangle.
             */
            Crop(int x, int y, int w, int h);

            /**
             * Performs the crop on the given image.
             * @return Pointer to a new Image of size w_×h_ containing the cropped region.
             */
            Image* apply(Image* img) override;
        };

    }
}

#endif // CROP_HPP
