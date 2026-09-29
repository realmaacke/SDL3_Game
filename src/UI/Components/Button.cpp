#include "UI/Components/Button.hpp"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include <iostream>

Button::Button(
    float x, float y,
    int w, int h,
    std::string name,
    int zIndex,
    bool isVissible,
    bool isInteractable
) {
    this->x = x;
    this->y = y;
    this->width = w;
    this->height = h;
    this->name = name;
    this->zIndex = zIndex;
    this->isVissible = isVissible;
    this->isInteractable = isInteractable;
}

void Button::render(SDL_Renderer* renderer) {
    SDL_Vertex v[4];

    SDL_FPoint quad[4] = {
        {this->x, this->y},
        {this->x + this->width, this->y},
        {this->x + width, this->y + this->height},
        {this->x, this->y + this->height}
    };


    for (int i = 0; i < 4; i++) {
        v[i].position = quad[i];
        v[i].color = {0.0f, 0.0f, 1.0f, 1.0f};
        v[i].tex_coord = {0, 0};
    }
    const int idx[6] = {0, 1, 2, 0, 2, 3};
    SDL_RenderGeometry(renderer, nullptr, v, 4, idx, 6);
}

void Button::onTrigger(const SDL_Event& event) {

}

void Button::onToggle(const SDL_Event& event) {

}

void Button::onClick(const SDL_Event& event) {
    if (!this->isInteractable) return;
    
    if ((event.button.x > this->x && event.button.x < this->x + this->width) &&
        (event.button.y > this->y && event.button.y < this->y + this->height)
    ) {
        std::cout << "Inside" << std::endl;
    }
}