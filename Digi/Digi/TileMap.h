#pragma once
#include <vector>
#include "Node.h"
#include "MacroValues.h"
#include "SpriteList.h"
extern class SpriteList;
class TileMap
{
public:
	TileMap();
	TileMap(int id, bool activeRoom);
	TileMap(int mapArray[32][40]);
	~TileMap();
	void LoadMap(int index);
	void LoadNeighbours(int id);
	void SetNode(int x, int y);
	std::vector<TileMap*> Neighbours; // 0 up, 1 top right, 2 right, 3 bottom right, etc.
	std::vector<std::vector<Node*>> Tiles;
};

