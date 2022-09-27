//
// Created by Alexander Winter on 2022-09-27.
//

#ifndef WIZENGINEQUICKSTART_TGUISCREEN_H
#define WIZENGINEQUICKSTART_TGUISCREEN_H

#include "WIZ/game/Screen.h"
#include "WIZ/game/WindowListener.h"

class TGUIScreen : public wiz::Screen, public wiz::WindowListener {
	std::string name = "TGUIScreen";
	
public:
	TGUIScreen(wiz::Game& game);

	void tick(float delta) override;

	void render(sf::RenderTarget& target) override;

	void show() override;

	void hide() override;

	const std::string& getName() const override;

	void windowClosed() override;
};


#endif //WIZENGINEQUICKSTART_TGUISCREEN_H
