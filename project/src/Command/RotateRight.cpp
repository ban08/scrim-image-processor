#include "Command/RotateRight.hpp"
#include "Image.hpp"

namespace prog {
  namespace command {

    RotateRight::RotateRight() : Command("rotate_right") {}

    Image* RotateRight::apply(Image* img) {
      if (!img) return nullptr;

      int w = img->width();   // original image width
      int h = img->height();  // original image height

      // After rotation: width and height swap
      Image* newImg = new Image(h, w);

      for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
          // 90° clockwise
          // (x, y) → (newX = h - 1 - y, newY = x)
          newImg->at(h - 1 - y, x) = img->at(x, y);
        }
      }

      return newImg;
    }

  }
}
