//
// Created by Alexander Winter on 2022-02-11.
//

#include "asset/AssetLoader.h"

AssetLoader::AssetLoader(const Logger& logger)
    : logger(logger) {}


void AssetLoader::update(long time) {

}

float AssetLoader::getProgress() const {
    return static_cast<float>(getLoaded()) / static_cast<float>(getTotal());
}

uint32_t AssetLoader::getLoaded() const {
    return 0;
}

uint32_t AssetLoader::getTotal() const {
    return 0;
}
