//
// Created by Winter on 12/02/2022.
//

#include "HelloSFMLScreen.h"
#include "SFML/Window/Touch.hpp"
#include "SFML/Network/TcpSocket.hpp"
#include "SFML/Network/IpAddress.hpp"
#include <string>
#include <iostream>
#include "Box2DTestScreen.h"


HelloSFMLScreen::HelloSFMLScreen(wiz::Game& game)
	: Screen(game) {
}

void HelloSFMLScreen::tick(float delta) {

	sf::Vector2f vec(getGame().getWindow().getView().getSize());
	vec.x /= static_cast<float>(background.getTextureRect().getSize().x);
	vec.y /= static_cast<float>(background.getTextureRect().getSize().y);

	background.setScale(vec);

	sf::Vector2f spritePos = player.getPosition();
	sf::Vector2f msgPos = message.getPosition();

	bool playPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)
						|| sf::Joystick::isButtonPressed(0, 0);
	bool stopPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)
					   || sf::Joystick::isButtonPressed(0, 1);

	bool soundPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left)
						|| sf::Joystick::isButtonPressed(0, 2);

	if(playPressed && !wasPlayPressed)
	{
		music->play();
		getLogger().info("Playing music!");
	}
	else if(stopPressed && !wasStopPressed)
	{
		music->pause();
		getLogger().info("Stopping music!");
	}

	if(soundPressed && !wasSoundPressed)
	{
		auto mousePos = sf::Mouse::getPosition(getGame().getWindow());
		spritePos.x = (float) mousePos.x;
		spritePos.y = (float) mousePos.y;
		sound.play();
	}

	wasPlayPressed = playPressed;
	wasStopPressed = stopPressed;
	wasSoundPressed = soundPressed;

	spritePos.x += speed * delta * sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
	spritePos.y += speed * delta * sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y);
	msgPos.x += speed * delta * sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U);
	msgPos.y += speed * delta * sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::V);

	msgPos.x = std::clamp(msgPos.x, 0.0f, 100.0f);
	msgPos.y = std::clamp(msgPos.y, 0.0f, 100.0f);

	player.setPosition(spritePos);
	message.setPosition(msgPos);
}

void HelloSFMLScreen::render(sf::RenderTarget& target) {
	target.clear();
	target.draw(background);
	target.draw(message);
	target.draw(player);
	target.draw(circle);
}

void HelloSFMLScreen::show() {

	music = getGame().getAssets().get(GameAssets::GREENLIFE);
	music->setVolume(100.0f);

	sound.setBuffer(*getGame().getAssets().get(GameAssets::JUMP));

	message.setString("Welcome to SFML valley.");
	message.setFont(*getGame().getAssets().get(GameAssets::SANS_TTF));

	player.setTexture(*getGame().getAssets().get(GameAssets::PLAYER));
	player.setOrigin(sf::Vector2f(player.getTextureRect().getSize() / 2));
	player.setPosition(sf::Vector2f(300, 200));
	player.setScale(sf::Vector2f(0.25f, 0.25f));

	background.setTexture(*getGame().getAssets().get(GameAssets::BACKGROUND));

	circle.setRadius(40.0);
	circle.setPosition(sf::Vector2f(100., 100.));
	circle.setFillColor(sf::Color::Yellow);

	sf::IpAddress address("localhost");
	uint16_t port = 2020;
	sf::Time delay = sf::seconds(1.0f);
	getLogger().info("Attempting to connect to: " + address.toString() + ":" + std::to_string(port));
	sf::TcpSocket socket;
	sf::Socket::Status status = socket.connect(address, port, delay);

	if (status != sf::Socket::Done) {
		getLogger().error("NETWORK NOT FOUND !! BOOT UP THE SERVER !!!!");
	}
	else
	{
		char data[100];
		std::size_t received;
		if(socket.receive(data, 100, received) != sf::Socket::Done)
		{
			getLogger().error("ERROR WITH THE RECEIVED MSG !!!!");
		}
		else
		{
			std::stringstream ss;
			ss << "Received " << received << " bytes" << std::endl;
			ss << "Server Says: " << data << std::endl;
			getLogger().info(ss.str());
		}
	}

	getGame().addWindowListener(this);
}

void HelloSFMLScreen::hide() {
	getGame().removeWindowListener(this);
}

const std::string& HelloSFMLScreen::getName() const {
	return name;
}

void HelloSFMLScreen::windowClosed() {
	getGame().getWindow().close();
}
