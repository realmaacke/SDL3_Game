#pragma once
#include "Render/Layer.hpp"


class UserInterface : public Layer {
public:
    UserInterface();

    void render(SDL_Renderer* renderer) override;
};