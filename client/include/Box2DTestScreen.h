//
// Created by Alexander Winter on 2022-03-29.
//

#ifndef WIZENGINEQUICKSTART_CLIENT_BOX2DTESTSCREEN_H
#define WIZENGINEQUICKSTART_CLIENT_BOX2DTESTSCREEN_H


#include "WIZ/game/Screen.h"
#include "WIZ/game/WindowListener.h"
#include "Box2D/Dynamics/b2World.h"
#include "SFML/Graphics/Sprite.hpp"

class Box2DTestScreen : public wiz::Screen, public wiz::WindowListener {
	std::string name = "Box2DTestScreen";

	b2World world;
	sf::Sprite sprite;

public:
	Box2DTestScreen(wiz::Game& game);

	void tick(float delta) override;

	void render(sf::RenderTarget& target) override;

	void show() override;

	void hide() override;

	const std::string& getName() const override;

	void windowClosed() override;
};


#endif //WIZENGINEQUICKSTART_CLIENT_BOX2DTESTSCREEN_H
