#pragma once
#include <map>
#include "SFML/Graphics.hpp"
#include "SpriteList.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <fstream>

#define VALUE_HEALTH 0
#define VALUE_SPEED 1
#define VALUE_ARMOUR 2

#define DIRECTION_UP 0
#define DIRECTION_RIGHT 1
#define DIRECTION_DOWN 2
#define DIRECTION_LEFT 3

extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;

extern const int ABILITY_ONE_POSY;
extern const int ABILITY_ONE_POSX;

extern const int GRID_ROWS;
extern const int GRID_COLUMNS;

extern const int MINI_HEALTH_RED;
extern const int MINI_HEALTH_GREEN;
extern const int LARGE_HEALTH_RED;
extern const int LARGE_HEALTH_GREEN;

extern std::map<int, sf::Texture*> textureMap;
extern std::map<int, sf::Texture*> texturePlayer;

extern int grid[100][100];
extern int map1[32][40];
extern int map2[32][40];
extern int mapsAmount;
extern int currentMap;
extern std::map<int, int[32][40]> mapList;
extern SpriteList* sprites;
extern sf::Sprite selectedSprite;
extern int spriteIndex;

void init();
