#pragma once
#include <vector>
#include "Node.h"
#include "MacroValues.h"
class TileMap
{
public:
	TileMap();
	TileMap(int id, bool activeRoom);
	~TileMap();
	void LoadMap(int index);
	void LoadNeighbours(int id);
	std::vector<TileMap*> Neighbours; // 0 up, 1 top right, 2 right, 3 bottom right, etc.
	std::vector<std::vector<Node*>> Tiles;
};

