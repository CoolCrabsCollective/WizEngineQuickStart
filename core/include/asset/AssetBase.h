//
// Created by Alexander Winter on 2022-02-11.
//

#ifndef GAMETEMPLATE_ASSETBASE_H
#define GAMETEMPLATE_ASSETBASE_H


#include <string>

class AssetBase {
public:
    virtual ~AssetBase() = default;

    virtual void* load() const = 0;

    virtual void dispose(void* data) const = 0;

    virtual const std::string& getName() const = 0;
};


#endif //GAMETEMPLATE_ASSETBASE_H
