#pragma once

#include "Command.hpp"
#include <vector>
#include <string>

namespace prog {
    namespace command {

/**
 * Command to execute a sequence of SCRIM scripts in order.
 * Skips blank, open, and save commands within each script,
 * and prevents infinite recursion by tracking visited files.
 */
        class Chain : public Command {
        public:
            /**
             * @param commandName  Name of this command (should be "chain")
             * @param files        List of SCRIM filenames to execute in sequence
             */
            explicit Chain(std::string commandName, const std::vector<std::string> &files);
            ~Chain() override = default;

            /**
             * Applies each listed SCRIM to the given image:
             * - Parses the SCRIM file
             * - Executes its commands except blank/open/save
             * - Chains the resulting image into the next script
             * @return Modified image after all scripts
             */
            Image* apply(Image* img) override;

            /**
             * Reconstructs the original script line:
             * "chain <file1> <file2> ... end"
             */
            std::string toString() const override;

        private:
            std::vector<std::string> filenames_;  ///< SCRIM files to process
        };

    }
}

