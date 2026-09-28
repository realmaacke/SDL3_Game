#include "World.hpp"
#include "SDL3/SDL_rect.h"

World::World() {
    this->zIndex = 100;
    this->layerName = "World";
    this->isVissible = true;
}

void fillQuad(SDL_Renderer* r, const SDL_FPoint p[4]) {
    SDL_Vertex v[4];
    for (int i = 0; i < 4; i++) {
        v[i].position = p[i];
        v[i].color = {1.0f, 0.0f, 0.0f, 1.0f}; // R, G, B, A
        v[i].tex_coord = {0, 0};
    }
    const int idx[6] = {0, 1, 2, 0, 2, 3};
    SDL_RenderGeometry(r, nullptr, v, 4, idx, 6);
}
void World::render(SDL_Renderer* renderer) {
    SDL_FPoint quad[4] = {{100, 100}, {300, 100}, {300, 300}, {100, 300}};
    fillQuad(renderer, quad);
}