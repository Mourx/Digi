#pragma once
#include "SFML/Window.hpp"
#include "GameEngine.h"

extern class GameEngine;

class InputHandler
{
public:
	InputHandler(GameEngine* engine);
	~InputHandler();
	void checkKeyboard();
	void checkMouse(sf::Vector2f pos);
	void scrollMouse(sf::Vector2f pos,float delta);
	GameEngine* engine;
};

