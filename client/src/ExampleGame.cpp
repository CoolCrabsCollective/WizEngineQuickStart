//
// Created by Winter on 12/02/2022.
//

#include "ExampleGame.h"

#include <utility>

ExampleGame::ExampleGame(std::shared_ptr<sf::RenderWindow> window,
						 std::shared_ptr<wiz::Logger> logger,
						 std::shared_ptr<wiz::AssetLoader> assetLoader)
	: BasicGame(std::move(window), std::move(logger), std::move(assetLoader)) {}
