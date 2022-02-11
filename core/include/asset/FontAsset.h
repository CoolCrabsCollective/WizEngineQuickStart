//
// Created by Alexander Winter on 2022-02-11.
//

#ifndef GAMETEMPLATE_FONTASSET_H
#define GAMETEMPLATE_FONTASSET_H


#include "SFML/Graphics/Font.hpp"
#include "SinglePathAsset.h"

class FontAsset : public SinglePathAsset<sf::Font> {
public:
    FontAsset(const std::string& path);

    void* load() const override;
};


#endif //GAMETEMPLATE_FONTASSET_H
