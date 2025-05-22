#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "../Command.hpp"

namespace prog {
    namespace command {

/**
 * Slide command: shifts the image cyclically.
 * Pixels moved off one edge wrap around to the opposite edge.
 */
        class Slide : public Command {
            int dx_; ///< Horizontal shift amount (pixels)
            int dy_; ///< Vertical shift amount (pixels)

        public:
            /**
             * @param dx  Number of pixels to shift to the right (negative shifts left)
             * @param dy  Number of pixels to shift down (negative shifts up)
             */
            Slide(int dx, int dy);

            /**
             * Applies the slide operation to the provided image.
             *
             * @param img  Pointer to the image to be modified
             * @return     Pointer to the new slid image (caller is responsible for deletion),
             *             or nullptr if img is null
             */
            Image* apply(Image* img) override;
        };

    }
}

#endif // SLIDE_HPP
