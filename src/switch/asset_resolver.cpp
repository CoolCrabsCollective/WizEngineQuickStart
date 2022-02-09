//
// Created by Alexander Winter on 2022-02-07.
//

#ifdef OS_SWITCH

#include "asset_resolver.h"

std::string asset(const char* path) {
	return "romfs:/" + std::string(path);
}

#endif