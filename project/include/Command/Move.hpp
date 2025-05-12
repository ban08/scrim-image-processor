#ifndef MOVE_HPP
#define MOVE_HPP

#include "../Command.hpp"

namespace prog {
  namespace command{
    class Move : public Command {
        int dx_, dy_;
    public:
        Move(int dx, int dy);
        Image* apply(Image* img) override;
    };
}
}
#endif