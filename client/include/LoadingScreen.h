//
// Created by Winter on 12/02/2022.
//

#ifndef GAMETEMPLATE_LOADINGSCREEN_H
#define GAMETEMPLATE_LOADINGSCREEN_H


#include "HelloSFMLScreen.h"
#include "WIZ/game/Screen.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "ExampleGame.h"

class LoadingScreen : public wiz::Screen, public wiz::WindowListener {
	std::string name = "LoadingScreen";

	sf::Sprite sprite;
	sf::Text message;
public:
	LoadingScreen(wiz::Game& game);

	void tick(float delta) override;

	void render(sf::RenderTarget& target) override;

	void show() override;

	void hide() override;

	const std::string& getName() const override;

	void windowClosed() override;
};


#endif //GAMETEMPLATE_LOADINGSCREEN_H
