#include "os_finder.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstdint>
#include <logging/MultiLogger.h>
#include <logging/StdOutLogger.h>
#include <logging/DateTimeLoggerWrapper.h>
#include <logging/TagLoggerWrapper.h>

#include "asset_resolver.h"
#include "test_subdir/test_subdir.h"

#include "logging/DailyFileLogger.h"

#ifdef OS_SWITCH
	#include <switch.h>
#endif

int main(int argc, char* argv[])
{
#ifdef OS_SWITCH
    // with Yuzu, files are in ~/.local/share/yuzu/sdmc

    FILE* stdoutFile = fopen("stdout.txt", "a");
    FILE* stderrFile = fopen("stderr.txt", "a");

    dup2(fileno(stdoutFile), STDOUT_FILENO);
    dup2(fileno(stderrFile), STDERR_FILENO);

    fclose(stdoutFile);
    fclose(stderrFile);
#endif

    std::unique_ptr<Logger> logger = std::unique_ptr<Logger>(new TagLoggerWrapper(
            new DateTimeLoggerWrapper(
                new MultiLogger({
                    new DailyFileLogger("logs/", LogLevel::DEBUG),
                    new StdOutLogger(LogLevel::DEBUG)
                }), "[%H:%M:%S]")));

#ifdef OS_SWITCH
    logger->info("OS is Switch");
	// Setup NXLink
	socketInitializeDefault();
	nxlinkStdio();

	Result rc = romfsInit();
#endif

#ifdef OS_WINDOWS
    logger->info("OS is Windows");
#endif

#ifdef OS_MAC
    logger->info("OS is Mac");
#endif

#ifdef OS_UNIX
    logger->info("OS is Unix");
#endif
    testFunction();

#ifndef OS_SWITCH
	sf::Music music;

	if(!music.openFromFile(asset("greenlife.ogg"))) {
        logger->error("Failed to load music greenlife.ogg");
        return -1;
    }

	sf::SoundBuffer buffer;

	if(!buffer.loadFromFile(asset("jump.ogg"))) {
        logger->error("Failed to load sound jump.ogg");
        return -1;
    }

	sf::Sound sound;
	sound.setBuffer(buffer);

	music.setVolume(100.0f);
#endif

	sf::Font font;
	if(!font.loadFromFile(asset("sans.ttf")))
	{
        logger->error("Failed to load font sans.tff");
		return EXIT_FAILURE;
	}

	sf::VideoMode mode;

#ifdef OS_SWITCH
	mode = sf::VideoMode::getDesktopMode();
#else
	mode = sf::VideoMode(640, 480, 32);
#endif

	sf::Text message("Welcome to SFML valley.", font);

	sf::RenderWindow window(mode, "SFML Game Template Project");
	sf::Clock deltaClock;

    logger->info("Loading textures");
	sf::Texture playerTex;
	if(!playerTex.loadFromFile(asset("player.png"))) {
        logger->error("Failed to load texture player.png");
		return EXIT_FAILURE;
	}
	sf::Texture backgroundTex;
	if(!backgroundTex.loadFromFile(asset("background.jpg"))) {
        logger->error("Failed to load texture background.jpg");
		return EXIT_FAILURE;
	}
	sf::Sprite player;
	player.setTexture(playerTex);
	player.setOrigin(sf::Vector2f(player.getTextureRect().getSize() / 2));
	player.setPosition(sf::Vector2f(300, 200));
	sf::Sprite background;
	background.setTexture(backgroundTex);

#ifndef OS_SWITCH
	sf::CircleShape circle(40.f);
	circle.setPosition(sf::Vector2f(100., 100.));

	circle.setFillColor(sf::Color::Yellow);
#endif
	float speed = 0.02f;

	bool wasPlayPressed = false;
	bool wasStopPressed = false;

#ifndef OS_SWITCH
	std::string ip("localhost");
	uint16_t port = 2020;
	sf::Time delay = sf::seconds(1.0f);
    logger->info("Attempting to connect to: " + ip + ":" + std::to_string(port));
	sf::TcpSocket socket;
	sf::Socket::Status status = socket.connect(ip, port, delay);

	if (status != sf::Socket::Done) {
        logger->error("FUCK!!! NETWORK NOT FOUND !! BOOT UP THE SERVER !!!!");
	}
#endif

	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if(e.type == sf::Event::EventType::Closed) {
                logger->info("Good bye!");
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
#ifndef OS_SWITCH
		window.draw(circle);
#endif
		sf::Time dtTime = deltaClock.restart();
		float dt = dtTime.asSeconds();

		sf::Vector2f spritePos = player.getPosition();
		sf::Vector2f msgPos = message.getPosition();

		bool playPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P);
		bool stopPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);

#ifndef OS_SWITCH
		if(sf::Touch::isDown(1) || (playPressed && !wasPlayPressed))
		{
			music.play();
            logger->info("Playing music!");
		}
		else if(sf::Touch::isDown(2) || (stopPressed && !wasStopPressed))
		{
			music.pause();
            logger->info("Stopping music!");
		}
#endif

		wasPlayPressed = playPressed;
		wasStopPressed = stopPressed;

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
#ifndef OS_SWITCH
			auto mousePos = sf::Mouse::getPosition(window);
			spritePos.x = (float) mousePos.x;
			spritePos.y = (float) mousePos.y;
			sound.play();
#endif
		}
		else if(sf::Touch::isDown(0))
		{
#ifndef OS_SWITCH
			auto touchPos = sf::Touch::getPosition(0);
			spritePos.x = (float) touchPos.x;
			spritePos.y = (float) touchPos.y;
			sound.play();
#endif
		}
		else
		{
#ifndef OS_SWITCH
			spritePos.x += speed * dt * sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
			spritePos.y += speed * dt * -sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y);
			msgPos.x += speed * dt * sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U);
			msgPos.y += speed * dt * -sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::V);
#endif
		}

		player.setPosition(spritePos);
		message.setPosition(msgPos);

		window.display();
	}

#ifdef OS_SWITCH
	socketExit();
#endif
	return EXIT_SUCCESS;
}
