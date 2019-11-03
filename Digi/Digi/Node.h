#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

class Node {
public:
	Node();
	Node* Adjacent[4]; // Up, Right, Down, Left
	int travelCost;
	int totalTravelCost;
	float x, y;
	Node* nextNode;
	bool bPathable = false;
	bool bNewRoom = false;
	sf::Sprite icon;
	sf::Texture tex;
};
