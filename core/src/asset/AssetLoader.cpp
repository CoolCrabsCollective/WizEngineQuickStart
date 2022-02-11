//
// Created by Alexander Winter on 2022-02-11.
//

#include <chrono>
#include "asset/AssetLoader.h"
#include "SFML/Graphics/Texture.hpp"

AssetLoader::AssetLoader(const Logger& logger)
    : logger(logger) {}

AssetLoader::~AssetLoader() {

    for(auto const& x : map) {
        x.first->dispose(x.second);
    }
}

void AssetLoader::load(const AssetBase& asset) {
    map[&asset] = nullptr;
    logger.info("[AssetLoader] Added " + asset.getName() + " to loading queue");
}


void AssetLoader::update(std::chrono::duration<float, std::milli> duration) {

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for(auto const& x : map) {

        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();

        if(std::chrono::duration_cast<std::chrono::milliseconds>(now - begin) > duration)
            break;

        if(x.second != nullptr)
            continue;

        finishLoading(*x.first);
    }
}

void AssetLoader::finishLoading(const AssetBase& asset) {
    if(isLoaded(asset))
        return;

    try
    {
        void* pointer = asset.load();

        map[&asset] = pointer;
        logger.error("[AssetLoader] Loaded asset " + asset.getName());
        loaded++;
    }
    catch(std::exception& ex)
    {
        logger.error("[AssetLoader] Failed to load asset '" + asset.getName() + "', reason: " + ex.what());
    }
}

bool AssetLoader::isLoaded(const AssetBase& asset) const {
    return map[&asset] != nullptr;
}

float AssetLoader::getProgress() const {
    return static_cast<float>(getLoaded()) / static_cast<float>(getTotal());
}

uint32_t AssetLoader::getLoaded() const {
    return loaded;
}

uint32_t AssetLoader::getTotal() const {
    return map.size();
}
