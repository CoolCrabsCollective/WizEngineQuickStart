//
// Created by Alexander Winter on 2022-02-11.
//

#include <stdexcept>
#include "asset/SoundAsset.h"

SoundAsset::SoundAsset(const std::string& path)
    : SinglePathAsset(path) {}

void* SoundAsset::load() const {
    auto* sound = new sf::SoundBuffer();

    if(!sound->loadFromFile(path))
        throw std::runtime_error("Failed to load sound " + path);

    return sound;
}