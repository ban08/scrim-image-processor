#ifndef RESIZE_HPP
#define RESIZE_HPP

#include "../Command.hpp"
#include "../Color.hpp"

namespace prog {
    namespace command {

/**
 * Resize command: creates a new image of size w_×h_ by copying
 * a subregion from the original image starting at (x_, y_).
 */
        class Resize : public Command {
            int x_; ///< X-coordinate of the top-left corner of the source region
            int y_; ///< Y-coordinate of the top-left corner of the source region
            int w_; ///< Width of the output image (and region to copy)
            int h_; ///< Height of the output image (and region to copy)

        public:
            /**
             * @param x  X-coordinate of the top-left corner of the source region.
             * @param y  Y-coordinate of the top-left corner of the source region.
             * @param w  Width of the resized image.
             * @param h  Height of the resized image.
             */
            Resize(int x, int y, int w, int h);

            /**
             * Applies the resize operation to the given image.
             * Copies the region defined by (x_, y_) and size (w_, h_) into a new image.
             *
             * @param img  Pointer to the image to resize.
             * @return     Pointer to the new resized image (caller is responsible for deleting it).
             */
            Image* apply(Image* img) override;
        };

    }
}

#endif // RESIZE_HPP
