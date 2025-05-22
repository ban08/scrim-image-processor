#ifndef VMIRROR_HPP
#define VMIRROR_HPP

#include "../Command.hpp"

namespace prog {
    namespace command {

/**
 * VMirror command: flips the image vertically.
 * Swaps pixels top-to-bottom in each column.
 */
        class VMirror : public Command {
        public:
            /**
             * Default constructor.
             * Sets the command name to "v_mirror".
             */
            VMirror();

            /**
             * Applies the vertical mirror operation to the provided image.
             *
             * @param img Pointer to the image to modify.
             * @return    Pointer to the vertically mirrored image (same instance),
             *            or nullptr if img is null.
             */
            Image* apply(Image* img) override;
        };

    } 
}

#endif // VMIRROR_HPP
