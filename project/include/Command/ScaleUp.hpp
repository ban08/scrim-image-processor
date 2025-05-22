#ifndef SCALE_UP_HPP
#define SCALE_UP_HPP

#include "../Command.hpp"

namespace prog {
    namespace command {

/**
 * ScaleUp command: increases the size of an image by integer factors.
 * Uses nearest-neighbor sampling to replicate pixels.
 */
        class ScaleUp : public Command {
            int xScale_; ///< horizontal scaling factor (must be > 0)
            int yScale_; ///< vertical scaling factor (must be > 0)

        public:
            /**
             * @param xScale  Factor by which to multiply the image width.
             * @param yScale  Factor by which to multiply the image height.
             */
            ScaleUp(int xScale, int yScale);

            /**
             * Applies the scaling operation on the given image.
             *
             * @param img  Pointer to the image to be scaled.
             * @return     Pointer to the newly upscaled image (caller must delete),
             *             or the original image if img is null or factors are invalid.
             */
            Image* apply(Image* img) override;
        };

    }
}

#endif // SCALE_UP_HPP
