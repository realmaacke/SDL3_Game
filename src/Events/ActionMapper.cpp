#include "Events/ActionMapper.hpp"
#include "Events/ActionLoader.hpp"

#include "Output/Output.hpp"
#include "Output/OutputCodes.hpp"

#include "SDL3/SDL_events.h"
#include "SDL3/SDL_filesystem.h"
#include "SDL3/SDL_keyboard.h"
#include "SDL3/SDL_scancode.h"

#include <filesystem>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>


void ActionMapper::loadBindings() {
    fs::path binds = fs::path(SDL_GetBasePath()) / "cfg" / "keybinds.bind";

    if (!fs::exists(binds)) {
        Output::error(OutputCode::DEFAULT_BIND_MISSING);
        return;
    }
    this->loader.init_file(binds);
    std::vector<ActionOperations> actions = this->loader.retriveActions();

    for (const ActionOperations& acts : actions) {
        if (acts.operation == "bind" && acts.key.has_value() && acts.target.has_value()) {
            SDL_Scancode code = SDL_GetScancodeFromName(acts.key->c_str());
            this->bindKey(code, acts.target.value());
        }
        else if (acts.operation == "unbind" && acts.key.has_value()) {
            SDL_Scancode code = SDL_GetScancodeFromName(acts.key->c_str());
            this->keys.erase(this->keys.find(code));
        }
    }
}

void ActionMapper::loadBindings(const std::string& bind_file) {
    fs::path binds = fs::path(SDL_GetBasePath()) / "cfg" / bind_file;

    if (!fs::exists(binds)) {
        Output::error(OutputCode::BIND_FILE_MISSING);
        return;
    }
    this->loader.init_file(binds);
}

void ActionMapper::bindKey(SDL_Scancode key, const std::string& action) {
    this->keys[key] = action;
}

void ActionMapper::onAction(const std::string& action, std::function<void()> fn) {
    this->handlers[action] = std::move(fn);
}

void ActionMapper::handle(const SDL_Event& e) {
    if (e.type != SDL_EVENT_KEY_DOWN || e.key.repeat) return;
    auto key = this->keys.find(e.key.scancode);
    if (key == this->keys.end()) return;
    auto handler = this->handlers.find(key->second);
    if (handler != this->handlers.end()) handler->second();
}

void ActionMapper::printHandlers() {
    for (const auto& handler : this->handlers) {
        std::cout << "handler: " << handler.first << std::endl;
    }

    for (const auto& action : this->keys) {
        std::cout << "key: " << action.first << "action: " << action.second << std::endl;
    }
}