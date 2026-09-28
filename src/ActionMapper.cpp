#include "ActionMapper.hpp"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_scancode.h"
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>

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
}