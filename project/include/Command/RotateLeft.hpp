#ifndef ROTATE_LEFT_HPP
#define ROTATE_LEFT_HPP

#include "../Command.hpp"

namespace prog {
    namespace command {

/**
 * RotateLeft command: rotates the image 90 degrees counterclockwise.
 * The output image dimensions are swapped (width ↔ height).
 */
        class RotateLeft : public Command {
        public:
            /**
             * Default constructor.
             * Initializes the command name to "rotate_left".
             */
            RotateLeft();

            /**
             * Applies a 90° counterclockwise rotation to the provided image.
             *
             * @param img  Pointer to the image to be rotated.
             * @return     Pointer to the newly rotated image (caller is responsible for deletion),
             *             or nullptr if img is null.
             */
            Image* apply(Image* img) override;
        };

    }
}

#endif // ROTATE_LEFT_HPP
