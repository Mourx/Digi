#include "SFML/Graphics.hpp"
#include <vector>
#include "MacroValues.h"
#include "TileMap.h"
#include <boost/serialization/serialization.hpp>


int main() {
	int mapTemp[32][40];
	std::copy(&map1[0][0], &map1[0][0] + 32 * 40, &mapTemp[0][0]);
	TileMap* tilemap = new TileMap();
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	sf::View camera = window.getDefaultView();
	camera.zoom(1);
	camera.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	camera.setSize(1280, 1024);


	while (window.isOpen()) {
		window.setView(camera);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed) {

			}
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Blue);
		window.display();
		
	}
	return 0;
}


void SaveMap() {
	
}

