#pragma once
#include "Events/ActionLoader.hpp"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_scancode.h"
#include <functional>
#include <string>
#include <unordered_map>
#include <filesystem>

namespace fs = std::filesystem;

class ActionMapper {
public:
    /*Overload with const std::string& bind_file*/
    void loadBindings();
    void loadBindings(const std::string& bind_file);

    void bindKey(SDL_Scancode key, const std::string& action);
    void onAction(const std::string& action, std::function<void()> fn);
    void handle(const SDL_Event& e);


    void printHandlers();

private:
    ActionLoader loader;
    std::unordered_map<SDL_Scancode, std::string> keys;
    std::unordered_map<std::string, std::function<void()>> handlers;
};