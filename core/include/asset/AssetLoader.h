//
// Created by Alexander Winter on 2022-02-11.
//

#ifndef GAMETEMPLATE_ASSETLOADER_H
#define GAMETEMPLATE_ASSETLOADER_H


#include <cstdint>
#include <logging/Logger.h>
#include <map>
#include <memory>
#include <stdexcept>
#include "Asset.h"

class AssetLoader {
    const Logger& logger;

    mutable std::map<const AssetBase*, void*> map;

    uint32_t loaded = 0;
public:
    AssetLoader(const Logger& logger);

    AssetLoader(const AssetLoader&) = delete;

    virtual ~AssetLoader();

    void load(const AssetBase& asset);

    void update(std::chrono::duration<float, std::milli> duration);

    void finishLoading(const AssetBase& asset);

    template<class T>
    T* get(const Asset<T>& asset) const {
        void* pointer = map[&asset];

        if(pointer == nullptr)
            throw std::invalid_argument("Asset " + asset.getName() + " not loaded");

        return static_cast<T*>(pointer);
    }

    bool isLoaded(const AssetBase& asset) const;

    float getProgress() const;

    uint32_t getLoaded() const;

    uint32_t getTotal() const;
};


#endif //GAMETEMPLATE_ASSETLOADER_H
