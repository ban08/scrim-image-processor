#include "Command/Fill.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {

        // Construct a Fill command:
        // - x, y: top-left corner of the fill rectangle
        // - w, h: width and height of the fill rectangle
        // - c: fill color
        Fill::Fill(int x, int y, int w, int h, const Color& c)
                : Command("fill")
                , x_(x)
                , y_(y)
                , w_(w)
                , h_(h)
                , color_(c)
        {}

        // Apply fill to the given image
        Image* Fill::apply(Image* img) {
            if (!img)
                return nullptr;                 // no image to modify

            int imgW = img->width();
            int imgH = img->height();

            // Iterate over each row within the fill rectangle
            for (int yy = y_; yy < y_ + h_ && yy < imgH; ++yy) {
                if (yy < 0)
                    continue;                  // skip rows above image

                // Iterate over each column within the fill rectangle
                for (int xx = x_; xx < x_ + w_ && xx < imgW; ++xx) {
                    if (xx < 0)
                        continue;              // skip columns left of image

                    img->at(xx, yy) = color_;  // set pixel to fill color
                }
            }

            return img;
        }

    }
}
