#ifndef HMIRROR_HPP
#define HMIRROR_HPP

#include "../Command.hpp"

namespace prog {
  namespace command{
    class HMirror : public Command {
    public:
        HMirror();
        Image* apply(Image* img) override;
    };
}
}
#endif