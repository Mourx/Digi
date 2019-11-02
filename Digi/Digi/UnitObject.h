#pragma once

#include "GameObject.h"
#include "GameEngine.h"
#include "MacroValues.h"


class UnitObject : public GameObject {
public:
	UnitObject(int UnitTypeID, GameEngine* Engine, int nodeX, int nodeY);
	int getValue(int whichValue);
	void onRightClick(int x, int y, sf::Time time);
	void update(sf::Time time);
	void move(int direction);
	
	void animate();
	
protected:
	int sprite = 1;
	int animateTime = 0;
	int health, armour;
	sf::Time startTime;
	bool bMoving = false;
	int speed;
	Node* currentNode;
	Node* targetNode;
	
	int targetX = 0, targetY = 0;
	bool bIsAtDest = true;
	float remainingDistX = 0;
	float remainingDistY = 0;
	int dirX = 0, dirY = 0;
};