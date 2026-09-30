#include "Events/ActionLoader.hpp"
#include "Output/Output.hpp"
#include "Output/OutputCodes.hpp"
#include "SDL3/SDL_keyboard.h"
#include "SDL3/SDL_scancode.h"
#include <cstddef>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include <vector>

ActionLoader::ActionLoader() {

}

// todo: Rework parser to allow for more than one key (shift + key)
void ActionLoader::init_file(const std::string& file) {
    std::ifstream bindFile(file);

    if (!bindFile.is_open()) {
        Output::error(OutputCode::FILE_ACCESS_ERROR);
        return;
    }
    
    std::string row;
    while (std::getline(bindFile, row)) {
        if (row.rfind("#") != std::string::npos) continue;;

        if (row.empty()) continue;
        ActionOperations action;
        std::string col;
        std::stringstream ss(row);

        while (std::getline(ss, col, ' ')) {
            if (col == "bind") { action.operation = col; continue; }
            if (col == "unbind") { action.operation = col; continue; }

            if (!action.key.has_value()) {
                SDL_Scancode sc = SDL_GetScancodeFromName(col.c_str());

                if (sc == SDL_SCANCODE_UNKNOWN) {
                    Output::error(OutputCode::BIND_KEY_INVALID);
                    return;
                }
                action.key = col;
                continue;
            }
            action.target = col;
        }
        this->bind_ops.push_back(action);
    }
}

std::vector<ActionOperations> ActionLoader::retriveActions() {
    return this->bind_ops;
}