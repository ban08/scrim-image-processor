#ifndef RESIZE_HPP
#define RESIZE_HPP

#include "../Command.hpp"
#include "../Color.hpp"

namespace prog {
  namespace command{
    class Resize : public Command {
        int x_, y_, w_, h_;
    public:
        Resize(int x, int y, int w, int h);
        Image* apply(Image* img) override;
    };
}
}
#endif