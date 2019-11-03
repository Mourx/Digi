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

void TileMap::LoadMap(int index) {
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
			tile->icon.setPosition(tile->x,tile->y);
			sf::Texture tex;
			tile->icon.setScale(1, 1);
			switch (map1[i][j]) {
			case(0):
				tile->bPathable = true;
				tile->icon.setTexture(*textureMap[0]);
				break;
			case(1):
				tile->icon.setTexture(*textureMap[1]);
				break;
			case(2):
				tile->icon.setTexture(*textureMap[2]);
				break;
			case(3):
				tile->icon.setTexture(*textureMap[3]);
				break;
			case(4):
				tile->icon.setTexture(*textureMap[4]);
				break;
			case(5):
				tile->icon.setTexture(*textureMap[5]);
				break;
			case(6):
				tile->icon.setTexture(*textureMap[6]);
				break;
			case(7):
				tile->icon.setTexture(*textureMap[7]);
				break;
			case(8):
				tile->icon.setTexture(*textureMap[8]);
				break;
			default:
				break;
			}
			row.push_back(tile);
		}
		Tiles.push_back(row);
	}
}