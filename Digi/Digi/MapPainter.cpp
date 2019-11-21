#include "SFML/Graphics.hpp"
#include <vector>
#include "MacroValues.h"
#include "TileMap.h"
#include <boost/serialization/serialization.hpp>
#include "Handler.h"
#include "GameEngine.h"
#include "Button.h"
#include <functional>
GameEngine* engine;
void SetupButtons(GameEngine* engine);
int mapTemp[32][40];
int main() {
	init();
	WINDOW_WIDTH += 100;
	std::copy(&map1[0][0], &map1[0][0] + 32 * 40, &mapTemp[0][0]);
	TileMap* tilemap = new TileMap();
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	sf::View camera = window.getDefaultView();
	engine = new GameEngine(camera);
	InputHandler* input = new InputHandler(engine);
	camera.zoom(1);
	camera.setCenter(WINDOW_WIDTH/ 2, WINDOW_HEIGHT / 2);
	camera.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	SetupButtons(engine);
	engine->map->LoadMap(1);
	while (window.isOpen()) {
		window.setView(camera);
		sf::Event event;
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		// convert it to world coordinates
		sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed) {

			}
			if (event.type == sf::Event::MouseWheelScrolled) {
				engine->input->scrollMouse(worldPos, (float)event.mouseWheelScroll.delta);
				std::cout << event.mouseWheelScroll.delta << ", " << sprites->offset << std::endl;
			}
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// get the current mouse position in the window
		

		input->checkMouse(worldPos);
		window.clear(sf::Color::Blue);
		for (int i = 0; i < engine->map->Tiles.size(); i++) {
			for (int j = 0; j < engine->map->Tiles[i].size(); j++) {
				window.draw(engine->map->Tiles[i][j]->icon);
			}
		}
		
		for (int i = 0;i < sprites->sprites.size(); i++) {
			window.draw(sprites->sprites[i]);
		}
		window.draw(engine->loadButton->icon);
		window.draw(engine->saveButton->icon);
		window.display();
		
	}
	return 0;
}


void SaveMap() {
	Handler* h = new Handler();
	h->serializeMap();
	printf("saved");
}

void LoadMap() {
	Handler* h = new Handler();
	h->LoadMap();
	printf("loaded");
	engine->map->LoadMap(currentMap);

}

void SetupButtons(GameEngine* engine) {
	engine->loadButton = new Button(LoadMap);
	engine->saveButton = new Button(SaveMap);

	//setup load image and place
	sf::Texture* tex = new sf::Texture();
	tex->loadFromFile("load.png", sf::IntRect(0, 0, 64, 32));
	engine->loadButton->icon.setTexture(*tex);
	engine->loadButton->icon.setPosition(1285, 960);
	engine->loadButton->icon.setScale(1, 1);

	sf::Texture* tex2 = new sf::Texture();
	tex2->loadFromFile("save.png", sf::IntRect(0, 0, 64, 32));
	engine->saveButton->icon.setTexture(*tex2);
	engine->saveButton->icon.setPosition(1285, 992);
	engine->saveButton->icon.setScale(1, 1);
}


