#include "Game.hpp"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_keycode.h"
#include "SDL3/SDL_messagebox.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"


Game::Game(int width, int height, const std::string& title) {
    this->w_properties = {
        width,
        height,
        title
    };

    this->state.running = true;

    this->_layerState.addLayer(this->world, this->input);
    this->_layerState.addLayer(this->userInterface, this->input);

    this->input.bindKey(SDL_SCANCODE_F5, "toggle_UserInterface");
    this->input.bindKey(SDL_SCANCODE_F6, "toggle_World");
}

int Game::init() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_ShowSimpleMessageBox(
            SDL_MESSAGEBOX_ERROR,
            "Error",
            "Error Initializing SDL3",
            nullptr
        );
        return 1;
    }
    
    WindowProperties props = this->getWinProperties();
    this->state.window = SDL_CreateWindow(
        props.title.c_str(),
        props.width,
        props.height,
        0
    );
    
    if (!this->getWindow()) {
        SDL_ShowSimpleMessageBox(
            SDL_MESSAGEBOX_ERROR,
            "Error",
            "Could not initialize window",
            nullptr            
        );
        return 1;
    }

    this->state.renderer = SDL_CreateRenderer(this->state.window, nullptr);

    if (!this->state.renderer) {
        SDL_ShowSimpleMessageBox(
            SDL_MESSAGEBOX_ERROR,
            "Error",
            "Could not create renderer",
            this->state.window
        );
    }

    return 0;
};

int Game::event(SDL_Event event) {
    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            this->state.running = false;
            return 1;
        }
        this->input.handle(event);
    }
    return 0;
};

int Game::update() {
    return 0;
};

int Game::render() {
    SDL_SetRenderDrawColor(this->state.renderer, 255, 255, 255, 255);
    SDL_RenderClear(this->state.renderer);
    this->_layerState.renderLayers(this->state.renderer);

    SDL_RenderPresent(this->state.renderer);
    return 0;
};

void Game::cleanup() {
    SDL_DestroyRenderer(this->state.renderer);
    SDL_DestroyWindow(this->state.window);
    SDL_Quit();
}

SDL_Window* Game::getWindow() {
    return this->state.window;
}

SDL_Renderer* Game::getRenderer() {
    return this->state.renderer;
}

bool Game::getGameLoop() {
    return this->state.running;
}

SDLState Game::getState() {
    return this->state;
}

WindowProperties Game::getWinProperties() {
    return this->w_properties;
}