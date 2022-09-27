//
// Created by Alexander Winter on 2022-09-27.
//

#include "TGUIScreen.h"
#include <TGUI/TGUI.hpp>


TGUIScreen::TGUIScreen(wiz::Game& game)
		: Screen(game) {

}

void TGUIScreen::tick(float delta) {

}

void TGUIScreen::render(sf::RenderTarget& target) {
	target.clear();
	target.setView(sf::View({50.0f, 50.0f}, {160.0f, 120.0f}));

}

void TGUIScreen::show() {
	getGame().addWindowListener(this);
}

void TGUIScreen::hide() {
	getGame().removeWindowListener(this);
}

const std::string& TGUIScreen::getName() const {
	return name;
}

void TGUIScreen::windowClosed() {
	getGame().getWindow().close();
}