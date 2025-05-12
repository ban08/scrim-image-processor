#ifndef SCALE_UP_HPP
#define SCALE_UP_HPP

#include "../Command.hpp"

namespace prog {
  namespace command{
    class ScaleUp : public Command {
        int xScale_, yScale_;
    public:
        ScaleUp(int xScale, int yScale);
        Image* apply(Image* img) override;
    };
}
}
#endif