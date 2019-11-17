#include "SpriteList.h"



SpriteList::SpriteList()
{
	for (int i = 0; i < 20; i++) {
		
		for (int j = 0; j < 10; j++) {
			sf::Sprite sprite;
			sf::Texture* tex = new sf::Texture();
			tex->loadFromFile("MapTextures.png", sf::IntRect( j * 32, i * 32,32,32));
			textures[0] = (tex);
			sprite.setTexture(*tex);
			sprite.setScale(1.5,1.5);
			sprite.setPosition(1285 + 48 * (j % 2), 0 + (sprites.size() / 2) * 48);
			sprites.push_back(sprite);
			
		}

	}

}

SpriteList::~SpriteList()
{

}
