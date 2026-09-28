#pragma once
#include "ActionMapper.hpp"
#include "Render/LayerState.hpp"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_render.h"
#include "UserInterface.hpp"
#include "World.hpp"
#include <SDL3/SDL.h>
#include <string>

struct SDLState {
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
};

struct WindowProperties {
    int width;
    int height;
    std::string title;
};


class Game {
public:
    Game(int width, int height, const std::string& title);

    int init();
    int event(SDL_Event event);
    int update();
    int render();


    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();
    bool getGameLoop();
    SDLState getState();
    WindowProperties getWinProperties();
private:
    void cleanup();
    SDLState state;
    WindowProperties w_properties;

    LayerState _layerState;
    ActionMapper input;

    UserInterface userInterface;
    World world;
};