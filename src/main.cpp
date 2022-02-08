#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "asset_resolver.h"

#ifdef SWITCH
	#include <switch.h>
#endif

extern int main()
{
#ifdef SWITCH
    // Setup NXLink
    socketInitializeDefault();
    nxlinkStdio();

    Result rc = romfsInit();
#endif
    
    sf::Music music;

    if(!music.openFromFile(asset("sample.wav")))
        return -1;

    sf::Font font;
    if(!font.loadFromFile(asset("sans.ttf")))
    {
        std::cout << "Font not loaded" << std::endl;
        return EXIT_FAILURE;
    }

    sf::VideoMode mode;

#ifdef SWITCH
	mode = sf::VideoMode::getDesktopMode();
#else
	mode = sf::VideoMode(640, 480, 32);
#endif

    sf::Text message("Welcome to SFML valley.", font);

    sf::RenderWindow window(mode, "SFML Game Template Project");
    sf::Clock deltaClock;

	std::cout << "Loading textures" << std::endl;
    sf::Texture playerTex;
	if(!playerTex.loadFromFile(asset("player.png"))) {
		std::cout << "Texture failed to load" << std::endl;
        return EXIT_FAILURE;
    }
	sf::Texture backgroundTex;
	if(!backgroundTex.loadFromFile(asset("background.jpg"))) {
		std::cout << "Texture failed to load" << std::endl;
		return EXIT_FAILURE;
	}
    sf::Sprite player;
    player.setTexture(playerTex);
	sf::Sprite background;
	background.setTexture(backgroundTex);

    sf::CircleShape circle(40.f);
    circle.setPosition(sf::Vector2f(100., -100.));

    circle.setFillColor(sf::Color::Magenta);

    float speed = 0.02f;

	bool wasPlayPressed = false;
	bool wasStopPressed = false;

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
	        if(e.type == sf::Event::EventType::Closed) {
		        std::cout << "Good bye!" << std::endl;
		        window.close();
		        break;
	        }
        }

		if(!window.isOpen())
			break;

        window.clear();

	    sf::Vector2f vec = sf::Vector2f(window.getView().getSize());
		vec.x /= static_cast<float>(background.getTextureRect().getSize().x);
		vec.y /= static_cast<float>(background.getTextureRect().getSize().y);

	    background.setScale(vec);
        window.draw(background);
        window.draw(message);
	    player.setScale(sf::Vector2f(0.25f, 0.25f));
        window.draw(player);
		window.draw(circle);
        sf::Time dtTime = deltaClock.restart();
        float dt = dtTime.asSeconds();

        sf::Vector2f spritePos = player.getPosition();
        sf::Vector2f msgPos = message.getPosition();

		bool playPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P);
		bool stopPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);

        if(sf::Touch::isDown(1) || (playPressed && !wasPlayPressed))
        {
            music.play();
			std::cout << "Playing music!" << std::endl;
        }
		else if(sf::Touch::isDown(2) || (stopPressed && !wasStopPressed))
        {
            music.pause();
	        std::cout << "Stopping music!" << std::endl;
        }

	    wasPlayPressed = playPressed;
		wasStopPressed = stopPressed;

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			auto mousePos = sf::Mouse::getPosition();
			spritePos.x = (float) mousePos.x;
			spritePos.y = (float) mousePos.y;
		}
        else if(sf::Touch::isDown(0))
        {
            auto touchPos = sf::Touch::getPosition(0);
            spritePos.x = (float) touchPos.x;
            spritePos.y = (float) touchPos.y;
        }
		else
        {
            spritePos.x += speed * dt * sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
            spritePos.y += speed * dt * -sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y);
            msgPos.x += speed * dt * sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U);
            msgPos.y += speed * dt * -sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::V);
        }

        player.setPosition(spritePos);
        message.setPosition(msgPos);

        window.display();
    }

#ifdef SWITCH
    socketExit();
#endif
    return EXIT_SUCCESS;
}