//
// Created by Alexander Winter on 2022-02-13.
//

#include <vector>
#include <WIZ/asset/AssetBase.h>

namespace GameAssets {
	std::vector<const wiz::AssetBase*> ALL = std::vector<const wiz::AssetBase*>();
}

#define ASSET(TYPE, NAME, CONSTRUCTOR) TYPE NAME CONSTRUCTOR; int NAME##_INDEX = (ALL.push_back(&NAME), ALL.size() - 1);

#include "GameAssets.h"