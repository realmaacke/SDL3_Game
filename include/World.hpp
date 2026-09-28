#pragma once
#include "Render/Layer.hpp"
#include "SDL3/SDL_render.h"

class World : public Layer {
public:
    World();

    void render(SDL_Renderer* renderer) override;
    
};