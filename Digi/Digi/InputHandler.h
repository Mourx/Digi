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
	GameEngine* engine;
};

