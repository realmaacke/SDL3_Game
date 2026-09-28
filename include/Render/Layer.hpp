#pragma once
#include "SDL3/SDL_render.h"
#include <string>

class Layer {
public:
    std::string layerName = "";
    int zIndex = 0;
    bool isVissible = true;

    virtual ~Layer() = default;
    virtual void render(SDL_Renderer* renderer) = 0;
};