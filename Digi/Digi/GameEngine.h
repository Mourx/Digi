#pragma once

#include "Node.h"
#include "MacroValues.h"
#include "InputHandler.h"
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "TileMap.h"

class Player {
public:
	Player();

	InputHandler* input = new InputHandler();
	bool bMouseHeld = false;
	sf::RectangleShape selectionRect = sf::RectangleShape(sf::Vector2f(0, 0));
};

class GameEngine {
public:
	GameEngine();
	std::vector<Player*> playerList;
	std::vector<GameObject*> unitList;
	TileMap* map = new TileMap(0);
	void ConvertToNodes(int grid[100][100], std::vector<std::vector<Node*>> nodes);
	void AssignAdjacent(int Direction, Node* node, Node* next);
	void AddUnit(GameObject* unit);
	void Update(sf::Time time);
};

