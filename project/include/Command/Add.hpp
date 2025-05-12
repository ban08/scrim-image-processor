#ifndef ADD_HPP
#define ADD_HPP

#include "../Command.hpp"
#include "../Image.hpp"
#include "../PNG.hpp"

namespace prog {
  namespace command{
    class Add : public Command {
        std::string filename_;
        Color neutral_;
        int x_, y_;
    public:
        Add(const std::string& filename, const Color& neutral, int x, int y);
        Image* apply(Image* img) override;
    };
}
}
#endif