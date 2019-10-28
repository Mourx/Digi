#include "TileMap.h"



TileMap::TileMap()
{
}

TileMap::TileMap(int id)
{
	LoadMap(id);
}

TileMap::~TileMap()
{
}

void TileMap::LoadMap(int index) {
	Node* tile;
	std::vector<Node*> row;
	for (int i = 0; i < 32; i++) {
		row.clear();
		for (int j = 0; j < 40; j++) {
			tile = new Node();
			tile->x = j;
			tile->y = i;
			switch (map1[i][j]) {
			case(0):
				break;
			default:
				break;
			}
			row.push_back(tile);
		}
		Tiles.push_back(row);
	}
}