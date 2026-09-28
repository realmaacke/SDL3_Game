#include "Render/LayerState.hpp"
#include "ActionMapper.hpp"
#include "Render/Layer.hpp"
#include <algorithm>
#include <iostream>

void LayerState::addLayer(Layer& layer, ActionMapper& input) {
    bool nameTaken = false;
    for (const Layer* l : this->layers) {
        if (l->layerName == layer.layerName) {
            nameTaken = true;
            break;
        }
    }

    if (nameTaken) {
        std::cout
            << "Layer name is already taken: "
            << layer.layerName 
            << std::endl;
        return;
    }
    // add toggle.
    input.onAction("toggle_" + layer.layerName, [this, name = layer.layerName] {
        this->toggleLayer(name);
    });

    this->layers.push_back(&layer);
}

void LayerState::toggleLayer(const std::string& layerName) {
    for (Layer* layer : this->layers) {
        if (layer->layerName == layerName) {
            layer->isVissible = !layer->isVissible;
            return;
        }
    }
}

void LayerState::renderLayers(SDL_Renderer* renderer) {
    this->sortLayers();

    for (Layer* layer : this->layers) {
        if (!layer->isVissible) continue;

        layer->render(renderer);
    }
}


void LayerState::sortLayers() {
    std::stable_sort(
        this->layers.begin(),
        this->layers.end(),
        compareLayerIndex
    );
}

bool LayerState::compareLayerIndex(const Layer* a, const Layer* b) {
    return a->zIndex > b->zIndex;
}