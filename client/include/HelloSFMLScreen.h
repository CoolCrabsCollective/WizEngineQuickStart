//
// Created by Winter on 12/02/2022.
//

#ifndef GAMETEMPLATE_HELLOSFMLSCREEN_H
#define GAMETEMPLATE_HELLOSFMLSCREEN_H


#include "GameAssets.h"
#include "WIZ/game/Screen.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include "SFML/Audio/Music.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

class HelloSFMLScreen : public wiz::Screen, public wiz::WindowListener {
	std::string name = "HelloSFMLScreen";

	sf::Sound sound;
	sf::Music* music;
	sf::Texture* playerTex, *backgroundTex;

	sf::Text message;

	sf::Sprite player;
	sf::Sprite background;

	sf::CircleShape circle;

	sf::Clock deltaClock;

	float speed = 0.02f;

	bool wasPlayPressed = false;
	bool wasStopPressed = false;
	bool wasSoundPressed = false;

public:
	HelloSFMLScreen(wiz::Game& game);

	void tick(float delta) override;

	void render(sf::RenderTarget& target) override;

	void show() override;

	void hide() override;

	const std::string& getName() const override;

	void windowClosed() override;
};


#endif //GAMETEMPLATE_HELLOSFMLSCREEN_H
