#pragma once
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_render.h"
#include <string>

class Component {
public:
    float x, y;
    int width, height;
    std::string name;
    int zIndex = 0;
    bool isVissible = true;
    bool isInteractable = true;


    virtual ~Component() = default;
    // add base functionality for loading img.
    virtual void render(SDL_Renderer* renderer) = 0;
    virtual void onTrigger(const SDL_Event& event) = 0;
    virtual void onClick(const SDL_Event& event) = 0;
    virtual void onToggle(const SDL_Event& event) = 0;

    // add stuff like loading the image.
    // 
};