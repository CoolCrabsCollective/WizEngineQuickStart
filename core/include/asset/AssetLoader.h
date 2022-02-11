//
// Created by Alexander Winter on 2022-02-11.
//

#ifndef GAMETEMPLATE_ASSETLOADER_H
#define GAMETEMPLATE_ASSETLOADER_H


#include <cstdint>
#include <logging/Logger.h>
#include <map>
#include <memory>
#include "Asset.h"

class AssetLoader {
    const Logger& logger;

    const std::map<const void*, void*> map;
public:
    AssetLoader(const Logger& logger);

    template<class T>
    void load(const Asset<T>& asset) {

    }

    template<class T>
    void finishLoading(const Asset<T>& asset) {

    }

    template<class T>
    T* get(const Asset<T>& asset) {
        void* pointer = map[&asset];

        if(pointer == nullptr)


        return (T*)pointer;
    }


    void update(long time);

    float getProgress() const;

    uint32_t getLoaded() const;

    uint32_t getTotal() const;
};


#endif //GAMETEMPLATE_ASSETLOADER_H
