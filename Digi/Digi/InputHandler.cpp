#include "InputHandler.h"



InputHandler::InputHandler(GameEngine* e)
{
	engine = e;
}


InputHandler::~InputHandler()
{
}

void InputHandler::checkKeyboard() {
	if (engine != NULL) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			engine->player->Move(DIRECTION_UP);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			engine->player->Move(DIRECTION_DOWN);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			engine->player->Move(DIRECTION_LEFT);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			engine->player->Move(DIRECTION_RIGHT);
		}
	}
}

void InputHandler::checkMouse(sf::Vector2f pos) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		printf("%d %d\n", sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
		if (pos.y >= 960 && pos.x > 1285 && pos.x < 1349) {
			if (pos.y >= 992) {
				engine->saveButton->OnClick();
			}
			else {
				engine->loadButton->OnClick();
			}
		}
		if (pos.x >= 1280) {
			engine->SelectSprite(pos.x, pos.y);
		}
		else {
			engine->SetNode(pos.x,pos.y);
		}
	}


}