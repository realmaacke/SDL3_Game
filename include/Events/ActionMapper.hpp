#pragma once
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_scancode.h"
#include <functional>
#include <string>
#include <unordered_map>

class ActionMapper {
public:
    void bindKey(SDL_Scancode key, const std::string& action);
    void onAction(const std::string& action, std::function<void()> fn);
    void handle(const SDL_Event& e);


    void printHandlers();

private:
    std::unordered_map<SDL_Scancode, std::string> keys;
    std::unordered_map<std::string, std::function<void()>> handlers;
};