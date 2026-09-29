#pragma once
#include "SDL3/SDL_render.h"
#include "UI/Components/Component.hpp"

class Button : public Component {
public:
    Button(
        float x, float y,
        int w, int h,
        std::string name,
        int zIndex,
        bool isVissible = true,
        bool isInteractable = true,
    );

    void render(SDL_Renderer* renderer) override;
    void onTrigger(const SDL_Event& event) override;
    void onClick(const SDL_Event& event) override;
    void onToggle(const SDL_Event& event) override;
private:

};