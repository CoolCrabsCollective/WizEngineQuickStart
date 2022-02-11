//
// Created by Alexander Winter on 2022-02-11.
//

#include "asset/TextureAsset.h"

#include <utility>
#include <stdexcept>

TextureAsset::TextureAsset(std::string path)
    : SinglePathAsset(std::move(path)) {}

void* TextureAsset::load() const {
    auto* texture = new sf::Texture();

    if(!texture->loadFromFile(path))
        throw std::runtime_error("Failed to load texture " + path);

    return texture;
}

