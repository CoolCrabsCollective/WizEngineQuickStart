//
// Created by Alexander Winter on 2022-02-11.
//

#ifndef GAMETEMPLATE_SOUNDASSET_H
#define GAMETEMPLATE_SOUNDASSET_H


#include "SinglePathAsset.h"
#include "SFML/Audio/SoundBuffer.hpp"

class SoundAsset : public SinglePathAsset<sf::SoundBuffer> {
public:
    SoundAsset(const std::string& path);

    void* load() const override;
};


#endif //GAMETEMPLATE_SOUNDASSET_H
