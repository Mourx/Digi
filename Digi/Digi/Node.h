#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

class Node {
public:
	Node();
	void LoadMap(int index);
	Node* Adjacent[4]; // Up, Right, Down, Left
	int travelCost;
	int totalTravelCost;
	float x, y;
	Node* nextNode;
	sf::Sprite icon;
	sf::Texture tex;
};
