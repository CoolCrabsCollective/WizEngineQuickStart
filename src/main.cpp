#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

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
    if (!font.loadFromFile(asset("sans.ttf")))
    {
        printf("Font not loaded\r\n");
        return EXIT_FAILURE;
    }

    sf::VideoMode mode = sf::VideoMode::getDesktopMode();

    sf::Text message("Hello, world!", font);

    sf::RenderWindow window(mode, "Hello World SFML Window");
    sf::Clock deltaClock;

    printf("Loading texture\n");
    sf::Texture texture;
    if (!texture.loadFromFile(asset("example.png"))) {
        printf("Texture failed to load\n");
        return EXIT_FAILURE;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::CircleShape circle(40.f);
    circle.setPosition(sf::Vector2f(100., -100.));

    // set the shape color to green
    circle.setFillColor(sf::Color::Magenta);

    float speed = 0.02f;

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            printf("Event: %u\n", e.type);
        }

        window.clear();
        
        window.draw(message);
        window.draw(sprite);
        sf::Time dtTime = deltaClock.restart();
        float dt = dtTime.asSeconds();

        sf::Vector2f spritePos = sprite.getPosition();
        sf::Vector2f msgPos = message.getPosition();

        if(sf::Touch::isDown(1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
        {
            music.play();
        }
		else if(sf::Touch::isDown(2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            music.pause();
        }

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

        sprite.setPosition(spritePos);
        message.setPosition(msgPos);

        window.display();
    }

#ifdef SWITCH
    socketExit();
#endif
    return EXIT_SUCCESS;
}