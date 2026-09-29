#pragma once
#include "Events/ActionMapper.hpp"
#include "Layers/Layer.hpp"

#include "SDL3/SDL_render.h"
#include <vector>

class LayerState {
public:
    void addLayer(Layer& layer, ActionMapper& input);
    void toggleLayer(const std::string& layerName);
    void renderLayers(SDL_Renderer* renderer);
private:
    static bool compareLayerIndex(
        const Layer* a,
        const Layer* b
    );
    void sortLayers();
    std::vector<Layer*> layers;
};