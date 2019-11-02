#include "InputHandler.h"



InputHandler::InputHandler(GameEngine* e)
{
	engine = e;
}


InputHandler::~InputHandler()
{
}

void InputHandler::checkKeyboard() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		engine->player->Move(0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

	}
}
