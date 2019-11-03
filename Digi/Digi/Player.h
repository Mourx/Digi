#pragma once

#include "UnitObject.h"

extern class UnitObject;

class Player
{
public:
	Player();
	~Player();	
	UnitObject* PC;
	bool bMouseHeld = false;
	void Move(int direction);
	sf::RectangleShape selectionRect = sf::RectangleShape(sf::Vector2f(0, 0));


};

