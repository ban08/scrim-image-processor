#ifndef INVERT_HPP
#define INVERT_HPP

#include "../Command.hpp"

namespace prog {
  namespace command{
    class Invert : public Command {
    public:
        Invert();
        Image* apply(Image* img) override;
    };
}
}

#endif