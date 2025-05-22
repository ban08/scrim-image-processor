#include "Command/RotateLeft.hpp"
#include "Image.hpp"

namespace prog {
  namespace command {

    RotateLeft::RotateLeft() : Command("rotate_left") {}

    Image* RotateLeft::apply(Image* img) {
      if (!img) return nullptr;

      int w = img->width();
      int h = img->height();

      Image* newImg = new Image(h, w);  // width becomes height

      for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
          // Rotate 90° counter-clockwise
          // Pixel at (x, y) → (newX = y, newY = w - 1 - x)
          newImg->at(y, w - 1 - x) = img->at(x, y);
        }
      }

      return newImg;
    }

  } // namespace command
} // namespace prog
