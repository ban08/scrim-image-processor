#ifndef ADD_HPP
#define ADD_HPP

#include "../Command.hpp"
#include "../Image.hpp"
#include "../PNG.hpp"

namespace prog {
    namespace command {

/**
 * Overlay a PNG image onto another image.
 * Pixels matching the neutral color are treated as transparent.
 */
        class Add : public Command {
            std::string filename_; ///< Path to the overlay PNG file
            Color neutral_;        ///< Color to treat as transparent in the overlay
            int x_, y_;            ///< Top-left position where overlay is applied

        public:
            /**
             * @param filename  PNG file to overlay
             * @param neutral   Color in the overlay to treat as transparent
             * @param x         Horizontal offset on the target image
             * @param y         Vertical offset on the target image
             */
            Add(const std::string& filename, const Color& neutral, int x, int y);

            /**
             * Applies the overlay to the given image.
             * @return Pointer to the (modified) image.
             */
            Image* apply(Image* img) override;
        };

    }
}

#endif // ADD_HPP
