//
// Created by Alexander Winter on 2022-02-07.
//

#ifndef OS_SWITCH

#include "asset_resolver.h"

std::string asset(const char* path) {
	return "res/" + std::string(path);
}

#endif