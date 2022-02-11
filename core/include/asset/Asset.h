//
// Created by Alexander Winter on 2022-02-11.
//

#ifndef GAMETEMPLATE_ASSET_H
#define GAMETEMPLATE_ASSET_H

template <typename T>
class Asset {
public:
    virtual ~Asset() = default;

    virtual T load() = 0;
};


#endif //GAMETEMPLATE_ASSET_H
