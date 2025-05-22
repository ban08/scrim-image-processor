// include/Command/Chain.hpp
#pragma once
#include "Command.hpp"
#include <vector>
#include <string>

namespace prog {
    namespace command {

        class Chain : public Command {
        public:
            explicit Chain(std::string commandName, const std::vector<std::string> &files);
            ~Chain() override = default;
            Image* apply(Image* img) override;
            std::string toString() const override;
        private:
            std::vector<std::string> filenames_;
        };

    }  // namespace command
}  // namespace prog
