#pragma once
#include <vector>
#include "SFML/Graphics.hpp"
class SpriteList
{
public:
	SpriteList();
	~SpriteList();

	std::map<int, sf::Texture*> textures;
	std::vector<sf::Sprite> sprites;
};

