//
// Created by Alexander Winter on 2022-02-07.
//


#include "asset_resolver.h"

std::string asset(const char* path) {
#ifdef OS_SWITCH
    return "romfs:/" + std::string(path);
#else
    return "res/" + std::string(path);
#endif
}
