#include "UI/UserInterface.hpp"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_mouse.h"
#include "SDL3/SDL_rect.h"
#include "UI/Components/Button.hpp"
#include "UI/Components/Component.hpp"
#include <memory>

UserInterface::UserInterface() {
    this->zIndex = 0;
    this->layerName = "UserInterface";
    this->isVissible = true;

    this->components.push_back(std::make_unique<Button>(0, 0, 500, 100, "button", 10, true));
}


void UserInterface::render(SDL_Renderer* renderer) {
    for (std::unique_ptr<Component>& comp : this->components) {
        comp->render(renderer);
    }
}

void UserInterface::onEvent(SDL_Event event) {
    if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN && event.button.button == SDL_BUTTON_LEFT) {
        for (std::unique_ptr<Component>& comp : this->components) {
            comp->onClick(event);
        }
    }
}