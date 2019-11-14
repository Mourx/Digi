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
	void getNeighbourNodes();
	void animate();
	bool checkArrived();
	void setShift(int direction);
protected:
	int sprite = 1;
	int animateTime = 0;
	float moveSpeed = 2;
	int health, armour;
	sf::Time startTime;
	bool bMoving = false;
	int speed;
	Node* currentNode;
	Node* targetNode;
	std::vector<Node*> adjacentNodes;
	int shiftDirection = -1;
	bool bShiftRoom = false;
	int targetX = 0, targetY = 0;
	bool bIsAtDest = true;
	float remainingDistX = 0;
	float remainingDistY = 0;
	int dirX = 0, dirY = 0;
	int diffX = 0, diffY = 0;
};