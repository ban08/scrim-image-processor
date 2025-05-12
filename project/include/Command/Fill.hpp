#ifndef FILL_HPP
#define FILL_HPP

#include "../Command.hpp"
#include "../Color.hpp"

namespace prog {
  namespace command{
    class Fill : public Command {
        int x_, y_, w_, h_;
        Color color_;
    public:
        Fill(int x, int y, int w, int h, const Color& c);
        Image* apply(Image* img) override;
    };
}
}
#endif