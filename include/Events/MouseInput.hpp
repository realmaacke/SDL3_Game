#pragma once
#include "SDL3/SDL_events.h"
#include <string>
#include <vector>

class Interactable {
    std::string interact_name;
    bool isInteractable = false;
};

class MouseInput {
public:
    void handle(SDL_Event event);
    // void onEvent(SDL_Event event);

private:
    std::vector<Interactable*> interacts;
};