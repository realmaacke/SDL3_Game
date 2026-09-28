#include "Game.hpp"
#include "SDL3/SDL_events.h"
#include <SDL3/SDL.h>
#include <string>

int main(int argc, char** argv) {
    Game game(800, 600, "Game title");

    game.init();

    while (game.getGameLoop()) {
        SDL_Event event {0};
        if (game.event(event)) break;
        if (game.update()) break;
        if (game.render()) break;
    }
    return 0;
}