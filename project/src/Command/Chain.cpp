#include "Command/Chain.hpp"
#include "./ScrimParser.hpp"
#include "Command/Blank.hpp"
#include "Command/Open.hpp"
#include "Command/Save.hpp"
#include "Logger.hpp"

#include <unordered_set>
#include <sstream>

using namespace prog;
using namespace prog::command;

// Construct a Chain command with the given name and list of SCRIM files
Chain::Chain(std::string commandName, const std::vector<std::string> &files)
        : Command(commandName)
        , filenames_(files)
{}

// Reconstruct the original "chain ... end" script line
std::string Chain::toString() const {
    std::ostringstream oss;
    oss << "chain";
    for (const auto &f : filenames_) {
        oss << " " << f;
    }
    oss << " end";
    return oss.str();
}

// Apply each SCRIM in sequence, skipping blank/open/save and avoiding recursion
Image* Chain::apply(Image* img) {
    // Track recursion depth and which files have been visited
    static thread_local int depth = 0;
    static thread_local std::unordered_set<std::string> visited;
    depth++;
    if (depth == 1) {
        visited.clear();
    }

    for (const auto &fname : filenames_) {
        // Skip files already processed in this chain to prevent infinite loops
        if (visited.count(fname)) {
            continue;
        }
        visited.insert(fname);

        // Parse the sub-SCRIM file
        ScrimParser parser;
        Scrim* sub = parser.parseScrim(fname);
        if (!sub) {
            continue;  // ignore parse errors
        }

        // Apply each command except Blank, Open, and Save
        for (auto* cmd : sub->getCommands()) {
            if (dynamic_cast<Blank*>(cmd) ||
                dynamic_cast<Open*>(cmd)  ||
                dynamic_cast<Save*>(cmd)) {
                continue;
            }
            img = cmd->apply(img);
        }
        delete sub;  // clean up the parsed SCRIM
    }

    depth--;
    if (depth == 0) {
        visited.clear();
    }
    return img;
}
