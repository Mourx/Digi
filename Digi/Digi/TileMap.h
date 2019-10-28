#pragma once
#include <vector>
#include "Node.h"
#include "MacroValues.h"
class TileMap
{
public:
	TileMap();
	TileMap(int id);
	~TileMap();
	void LoadMap(int index);
	std::vector<std::vector<Node*>> Tiles;
};

