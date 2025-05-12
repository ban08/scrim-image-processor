#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "../Command.hpp"

namespace prog {
  namespace command{
    class Slide : public Command {
        int dx_, dy_;
    public:
        Slide(int dx, int dy);
        Image* apply(Image* img) override;
    };
}
}
#endif