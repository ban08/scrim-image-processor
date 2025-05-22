#ifndef TO_GRAY_SCALE_HPP
#define TO_GRAY_SCALE_HPP

#include "../Command.hpp"

namespace prog {
    namespace command {

/**
 * ToGrayScale command: converts each pixel to grayscale
 * by setting R, G, and B channels to their average.
 */
        class ToGrayScale : public Command {
        public:
            /**
             * Default constructor.
             * Sets the command name to "to_gray_scale".
             */
            ToGrayScale();

            /**
             * Applies the grayscale conversion to the given image.
             *
             * @param img Pointer to the image to modify.
             * @return    Pointer to the modified image (same instance), or nullptr if img is null.
             */
            Image* apply(Image* img) override;
        };

    }
}

#endif // TO_GRAY_SCALE_HPP
