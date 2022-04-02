//
// Created by Alexander Winter on 2022-03-12.
//

#include "TitleScreen.h"
#include "GameAssets.h"
#include "HelloSFMLScreen.h"
#include "SFML/Window/Touch.hpp"
#include "Box2DTestScreen.h"

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


	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)
	   || sf::Joystick::isButtonPressed(0, 3))
	{
		getGame().setScreen(std::shared_ptr<HelloSFMLScreen>(new HelloSFMLScreen(getGame())));
		return;
	}

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Touch::isDown(1))
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

	int i;
	for(i = 0; true; i++) {
		if(!sf::Joystick::isConnected(i))
			break;

		sf::Joystick::Identification id = sf::Joystick::getIdentification(i);
		unsigned int buttonCount = sf::Joystick::getButtonCount(i);

		std::stringstream ss;

		if(sf::Joystick::hasAxis(i, sf::Joystick::Axis::X))
			ss << "X";

		if(sf::Joystick::hasAxis(i, sf::Joystick::Axis::Y))
			ss << "Y";

		if(sf::Joystick::hasAxis(i, sf::Joystick::Axis::U))
			ss << "U";

		if(sf::Joystick::hasAxis(i, sf::Joystick::Axis::V))
			ss << "V";

		if(sf::Joystick::hasAxis(i, sf::Joystick::Axis::Z))
			ss << "Z";

		if(sf::Joystick::hasAxis(i, sf::Joystick::Axis::R))
			ss << "R";

		if(sf::Joystick::hasAxis(i, sf::Joystick::Axis::PovX))
			ss << "pX";

		if(sf::Joystick::hasAxis(i, sf::Joystick::Axis::PovY))
			ss << "pY";

		getLogger().info("Found controller, Name: " + id.name +
					 ", VendorID: " + std::to_string(id.vendorId) +
					 ", ProductID: " + std::to_string(id.productId) +
					 ", ButtonCount: " + std::to_string(buttonCount) +
					 ", Axis: " + ss.str());
	}
	getLogger().info("Found " + std::to_string(i) + " controllers");
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
