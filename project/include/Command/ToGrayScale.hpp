#ifndef TO_GRAY_SCALE_HPP
#define TO_GRAY_SCALE_HPP

#include "../Command.hpp"

namespace prog {
  namespace command{
    class ToGrayScale : public Command {
    public:
        ToGrayScale();
        Image* apply(Image* img) override;
    };
}
}
#endif