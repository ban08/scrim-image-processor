#ifndef HMIRROR_HPP
#define HMIRROR_HPP

#include "../Command.hpp"

namespace prog {
    namespace command {

/**
 * HMirror command: flips the image horizontally.
 * Swaps pixels on each row from left to right.
 */
        class HMirror : public Command {
        public:
            /**
             * Default constructor.
             * Initializes the command name to "h_mirror".
             */
            HMirror();

            /**
             * Applies the horizontal mirror operation to the given image.
             *
             * @param img Pointer to the image to be modified.
             * @return Pointer to the horizontally mirrored image.
             */
            Image* apply(Image* img) override;
        };

    }
}

#endif // HMIRROR_HPP
