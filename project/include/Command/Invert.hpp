#ifndef INVERT_HPP
#define INVERT_HPP

#include "../Command.hpp"

namespace prog {
    namespace command {

/**
 * Invert command: flips each pixel's color by subtracting
 * each RGB channel from 255.
 */
        class Invert : public Command {
        public:
            /**
             * Default constructor.
             * Sets the command name to "invert".
             */
            Invert();

            /**
             * Applies color inversion to the provided image.
             *
             * @param img Pointer to the image to be modified.
             * @return Pointer to the inverted image (same instance), or nullptr if img is null.
             */
            Image* apply(Image* img) override;
        };

    }
}

#endif // INVERT_HPP
