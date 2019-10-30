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