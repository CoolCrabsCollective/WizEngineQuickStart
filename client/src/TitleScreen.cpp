//
// Created by Alexander Winter on 2022-03-12.
//

#include "TitleScreen.h"
#include "GameAssets.h"
#include "HelloSFMLScreen.h"

TitleScreen::TitleScreen(wiz::Game& game)
	: Screen(game) {}

void TitleScreen::tick(float delta) {
	sf::Vector2f vec(getGame().getWindow().getView().getSize());

	logo.setOrigin(sf::Vector2f(logo.getTextureRect().getSize() / 2));
	logo.setPosition(vec / 2.0f);
	//logo.setScale(sf::Vector2f(0.25f, 0.25f));

	vec.x /= static_cast<float>(background.getTextureRect().getSize().x);
	vec.y /= static_cast<float>(background.getTextureRect().getSize().y);
	background.setScale(vec);

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		getGame().setScreen(std::shared_ptr<HelloSFMLScreen>(new HelloSFMLScreen(getGame())));
}

void TitleScreen::render(sf::RenderTarget& target) {
	target.clear();
	target.draw(background);
	target.draw(logo);
}

void TitleScreen::show() {
	logo.setTexture(*getAssets().get(GameAssets::LOGO));
	background.setTexture(*getAssets().get(GameAssets::BACKGROUND));

	getGame().addWindowListener(this);
}

void TitleScreen::hide() {
	getGame().removeWindowListener(this);
}

const std::string& TitleScreen::getName() const {
	return name;
}

void TitleScreen::windowClosed() {
	getGame().getWindow().close();
}
