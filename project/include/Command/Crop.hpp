#ifndef CROP_HPP
#define CROP_HPP

#include "../Command.hpp"
#include "../Color.hpp"

namespace prog {
  namespace command{
    class Crop : public Command {
        int x_, y_, w_, h_;
    public:
        Crop(int x, int y, int w, int h);
        Image* apply(Image* img) override;
    };
}
}
#endif