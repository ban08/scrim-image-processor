#ifndef VMIRROR_HPP
#define VMIRROR_HPP

#include "../Command.hpp"

namespace prog {
  namespace command{
    class VMirror : public Command {
    public:
        VMirror();
        Image* apply(Image* img) override;
    };
}
}
#endif