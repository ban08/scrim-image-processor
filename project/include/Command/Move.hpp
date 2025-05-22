#ifndef MOVE_HPP
#define MOVE_HPP

#include "../Command.hpp"

namespace prog {
    namespace command {

/**
 * Move command: shifts the entire image by a given offset.
 * Pixels shifted outside the bounds are dropped, and new areas use the default fill color.
 */
        class Move : public Command {
            int dx_; ///< horizontal shift (positive moves right)
            int dy_; ///< vertical shift (positive moves down)

        public:
            /**
             * @param dx  Number of pixels to shift horizontally
             * @param dy  Number of pixels to shift vertically
             */
            Move(int dx, int dy);

            /**
             * Applies the shift to the provided image.
             *
             * @param img  Pointer to the image to be moved
             * @return     Pointer to the newly shifted image
             */
            Image* apply(Image* img) override;
        };

    }
}

#endif // MOVE_HPP
