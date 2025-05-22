#ifndef FILL_HPP
#define FILL_HPP

#include "../Command.hpp"
#include "../Color.hpp"

namespace prog {
    namespace command {

/**
 * Fill command: fills a rectangular area of the image with a solid color.
 * The rectangle is defined by its top-left corner (x_, y_) and size (w_ × h_).
 */
        class Fill : public Command {
            int x_;        ///< X-coordinate of the top-left corner of the fill area
            int y_;        ///< Y-coordinate of the top-left corner of the fill area
            int w_;        ///< Width of the fill area
            int h_;        ///< Height of the fill area
            Color color_;  ///< Color to fill the area with

        public:
            /**
             * @param x  X-coordinate of the top-left corner of the fill rectangle.
             * @param y  Y-coordinate of the top-left corner of the fill rectangle.
             * @param w  Width of the fill rectangle.
             * @param h  Height of the fill rectangle.
             * @param c  Color used for filling.
             */
            Fill(int x, int y, int w, int h, const Color& c);

            /**
             * Applies the fill to the given image.
             * @return Pointer to the modified image.
             */
            Image* apply(Image* img) override;
        };

    }
}

#endif // FILL_HPP
