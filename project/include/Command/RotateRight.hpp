#ifndef ROTATE_RIGHT_HPP
#define ROTATE_RIGHT_HPP

#include "../Command.hpp"

namespace prog {
    namespace command {

/**
 * RotateRight command: rotates the image 90 degrees clockwise.
 * The output image dimensions are swapped (width ↔ height).
 */
        class RotateRight : public Command {
        public:
            /**
             * Default constructor.
             * Sets the command name to "rotate_right".
             */
            RotateRight();

            /**
             * Applies a 90° clockwise rotation to the provided image.
             *
             * @param img  Pointer to the image to be rotated.
             * @return     Pointer to the newly rotated image (caller is responsible for deletion),
             *             or nullptr if img is null.
             */
            Image* apply(Image* img) override;
        };

    }
}

#endif // ROTATE_RIGHT_HPP
