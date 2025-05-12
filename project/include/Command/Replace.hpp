#ifndef REPLACE_HPP
#define REPLACE_HPP

#include "../Command.hpp"
#include "../Color.hpp"

namespace prog {
  namespace command{
    class Replace : public Command {
        Color oldColor;
        Color newColor;
    public:
        Replace(const Color& oldC, const Color& newC);
        Image* apply(Image* img) override;
    };
}
}
#endif