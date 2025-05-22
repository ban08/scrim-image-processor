#ifndef REPLACE_HPP
#define REPLACE_HPP

#include "../Command.hpp"
#include "../Color.hpp"

namespace prog {
    namespace command {

/**
 * Replace command: replaces all pixels matching a given color with a new color.
 */
        class Replace : public Command {
            Color oldColor;  ///< Color to be replaced
            Color newColor;  ///< Replacement color

        public:
            /**
             * @param oldC  Color value to search for in the image
             * @param newC  Color value to replace matching pixels with
             */
            Replace(const Color& oldC, const Color& newC);

            /**
             * Applies the color replacement on the provided image.
             *
             * @param img  Pointer to the image to modify
             * @return     Pointer to the modified image (same instance), or nullptr if img is null
             */
            Image* apply(Image* img) override;
        };

    }
}

#endif // REPLACE_HPP
