#include "InputHandler.h"



InputHandler::InputHandler(GameEngine* e)
{
	engine = e;
}


InputHandler::~InputHandler()
{
}

void InputHandler::checkKeyboard() {
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
