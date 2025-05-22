#include "Command/Add.hpp"
#include "Image.hpp"
#include "PNG.hpp"

namespace prog {
    namespace command {

        // Construct an Add command:
        // - filename: path to the PNG to overlay
        // - neutral: color to treat as transparent
        // - x, y: top-left position in the target image
        Add::Add(const std::string& filename, const Color& neutral, int x, int y)
                : Command("add")
                , filename_(filename)
                , neutral_(neutral)
                , x_(x)
                , y_(y)
        {}

        // Apply the overlay to the given image
        Image* Add::apply(Image* img) {
            if (!img)
                return nullptr;             // nothing to do if no base image

            // Load the overlay image from PNG file
            Image* overlay = loadFromPNG(filename_);
            if (!overlay)
                return img;                // if load fails, leave original unchanged

            int imgW = img->width();
            int imgH = img->height();
            int ovW  = overlay->width();
            int ovH  = overlay->height();

            // Loop over each pixel of the overlay
            for (int oy = 0; oy < ovH; ++oy) {
                int destY = y_ + oy;
                if (destY < 0 || destY >= imgH)
                    continue;                // skip rows outside target

                for (int ox = 0; ox < ovW; ++ox) {
                    int destX = x_ + ox;
                    if (destX < 0 || destX >= imgW)
                        continue;            // skip columns outside target

                    const Color& src = overlay->at(ox, oy);

                    // Copy pixel if it's not the neutral (transparent) color
                    if (src.red()   != neutral_.red() ||
                        src.green() != neutral_.green() ||
                        src.blue()  != neutral_.blue()) {
                        img->at(destX, destY) = src;
                    }
                }
            }

            delete overlay;
            return img;
        }

    }
}
