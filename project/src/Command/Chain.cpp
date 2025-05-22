// src/Command/Chain.cpp
#include "Command/Chain.hpp"
#include "./ScrimParser.hpp"
#include "./Scrim.hpp"
#include "Command/Blank.hpp"
#include "Command/Open.hpp"
#include "Command/Save.hpp"
#include "Logger.hpp"

#include <unordered_set>
#include <sstream>

using namespace prog;
using namespace prog::command;

Chain::Chain(std::string commandName, const std::vector<std::string> &files)
        : Command(commandName), filenames_(files) {}

std::string Chain::toString() const {
    std::ostringstream oss;
    oss << "chain";
    for (auto& f : filenames_) oss << " " << f;
    oss << " end";
    return oss.str();
}

Image* Chain::apply(Image* img) {
    // depth & visited guardam o contexto de chamadas para deter recursão
    static thread_local int depth = 0;
    static thread_local std::unordered_set<std::string> visited;
    depth++;
    if (depth == 1) visited.clear();

    for (auto& fname : filenames_) {
        if (visited.count(fname)) continue;           // deteta recursão
        visited.insert(fname);

        ScrimParser parser;
        Scrim* sub = parser.parseScrim(fname);
        if (!sub) continue;  // se houve erro a ler o ficheiro, ignora

        // aplica cada comando, mas ignora blank/open/save
        for (auto* cmd : sub->getCommands()) {
            if (dynamic_cast<command::Blank*>(cmd) ||
                dynamic_cast<command::Open*>(cmd)  ||
                dynamic_cast<command::Save*>(cmd)) {
                continue;
            }
            img = cmd->apply(img);
        }
        delete sub;  // destrói o Scrim e os seus comandos
    }

    depth--;
    if (depth == 0) visited.clear();
    return img;
}
