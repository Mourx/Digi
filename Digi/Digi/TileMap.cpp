#include "TileMap.h"



TileMap::TileMap()
{
}

TileMap::TileMap(int id, bool activeRoom)
{
	LoadMap(id);
	if (activeRoom) {
		LoadNeighbours(id);
	}
}

TileMap::TileMap(int mapArray[32][40]) {

}

TileMap::~TileMap()
{
}

void TileMap::LoadNeighbours(int id) {
	Neighbours.clear();
	for (int i = 0; i < 9; i++) {
		TileMap* neighbour = new TileMap(id, false);
		for (int k = 0; k < 32; k++) {


			for (int j = 0; j < 40; j++) {
				Node* node = neighbour->Tiles[k][j];
				if (i == 0 || i == 1 || i == 2) {
					node->y = node->y - 1024;
				}
				else if (i == 5 || i == 6 || i == 7) {
					node->y = node->y + 1024;
				}
				if (i == 0 || i == 3 || i == 5) {
					node->x = node->x - 1280;
				}
				else if (i == 2 || i == 4 || i == 7) {
					node->x = node->x + 1280;
				}

				node->icon.setPosition(node->x, node->y);
			}
		}
		Neighbours.push_back(neighbour);
	}
}

void TileMap::LoadMap(int index){
	Tiles.clear();
	std::vector<sf::Texture*> textures;
	
	
	std::vector<Node*> row;
	for (int i = 0; i < 32; i++) {
		
		row.clear();
		for (int j = 0; j < 40; j++) {
			Node* tile;
			tile = new Node();
			tile->x = j*32;
			tile->y = i*32;
			
			sf::Texture tex;
			
			switch (map1[i][j]) {
			default:
				tile->icon = (sprites->sprites[(map1[i][j])]);
				break;
			}
			if (map1[i][j]%10==0
) {
				tile->bPathable = true;
			}
			tile->icon.setPosition(tile->x, tile->y);
			tile->icon.setScale(1, 1);
			row.push_back(tile);
		}
		Tiles.push_back(row);
	}
}

void TileMap::SetNode(int x, int y) {
	//y = sprites->sprites.size() / 2 * 48 - y * 48;
	y = y / 32;
	x = x / 32;
	map1[y][x] = spriteIndex;
	Tiles[y][x]->icon = selectedSprite;
	Tiles[y][x]->icon.setPosition(Tiles[y][x]->x, Tiles[y][x]->y);
	Tiles[y][x]->icon.setScale(1, 1);
}