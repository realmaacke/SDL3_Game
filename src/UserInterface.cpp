#include "UserInterface.hpp"

UserInterface::UserInterface() {
    this->zIndex = 0;
    this->layerName = "UserInterface";
    this->isVissible = true;
}


void fillSquare(SDL_Renderer* r, const SDL_FPoint p[4]) {
    SDL_Vertex v[4];
    for (int i = 0; i < 4; i++) {
        v[i].position = p[i];
        v[i].color = {0.0f, 1.0f, 0.0f, 1.0f}; // R, G, B, A
        v[i].tex_coord = {0, 0};
    }
    const int idx[6] = {0, 1, 2, 0, 2, 3};
    SDL_RenderGeometry(r, nullptr, v, 4, idx, 6);
}
void UserInterface::render(SDL_Renderer* renderer) {
    SDL_FPoint quad[4] = {{200, 200}, {400, 200}, {400, 400}, {200, 400}};
    fillSquare(renderer, quad);
}