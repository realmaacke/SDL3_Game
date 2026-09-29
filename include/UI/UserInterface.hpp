#pragma once
#include "Layers/Layer.hpp"
#include "SDL3/SDL_events.h"
#include "UI/Components/Component.hpp"
#include <memory>
#include <vector>


class UserInterface : public Layer {
public:
    UserInterface();

    void render(SDL_Renderer* renderer) override;
    void onEvent(SDL_Event event);

private:
    std::vector<std::unique_ptr<Component>> components;

};