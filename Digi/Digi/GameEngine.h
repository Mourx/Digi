#pragma once

#include "Node.h"
#include "MacroValues.h"
#include "InputHandler.h"
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "TileMap.h"
#include "SFML/Window.hpp"
#include "UnitObject.h"
#include "Player.h"
#include "Button.h"

extern class InputHandler;
class Player;

class GameEngine {
public:
	
	GameEngine(sf::View window);
	Player* player;
	std::vector<GameObject*> unitList;
	TileMap* map = new TileMap(0,true);
	sf::View camera;
	void ConvertToNodes(int grid[100][100], std::vector<std::vector<Node*>> nodes);
	void AssignAdjacent(int Direction, Node* node, Node* next);
	void AddUnit(GameObject* unit);
	void Update(sf::Time time);
	void LoadNewRoom(int id);
	Node* getAdjacentTile(Node* startNode, int direction);
	InputHandler* input;
	void SetNode(int x, int y);
	void SelectSprite(int x, int y);
	Button* loadButton;
	Button* saveButton;
};

