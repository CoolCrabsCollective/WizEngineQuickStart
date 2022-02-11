//
// Created by Alexander Winter on 2022-02-11.
//

#include <stdexcept>
#include "asset/FontAsset.h"

FontAsset::FontAsset(const std::string& path)
    : SinglePathAsset(path) {}

void* FontAsset::load() const {
    auto* font = new sf::Font();

    if(!font->loadFromFile(path))
        throw std::runtime_error("Failed to load font " + path);

    return font;
}
