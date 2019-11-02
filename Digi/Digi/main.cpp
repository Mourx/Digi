#include <vector>
#include <SFML/Graphics.hpp>
#include "UnitObject.h"
#include "MacroValues.h"





int main() {

	init();
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	window.getSize();
	GameEngine* Engine = new GameEngine(window.getDefaultView());
	window.setView(Engine->camera);

	sf::Clock clock;
	
	
	
	while (window.isOpen())
	{
		sf::Time currentTime = clock.getElapsedTime();

		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{

			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		Engine->Update(currentTime);
		window.clear(sf::Color::Blue);
		
		for (int i = 0; i < Engine->map->Tiles.size(); i++) {
			
			for (int j = 0; j < Engine->map->Tiles[i].size(); j++) {
				window.draw(Engine->map->Tiles[i][j]->icon);
			
			
			}

		}
		for (int k = 0; k < Engine->map->Neighbours.size();k++) {
			for (int i = 0; i < Engine->map->Neighbours[k]->Tiles.size(); i++) {

				for (int j = 0; j < Engine->map->Neighbours[k]->Tiles[i].size(); j++) {
					window.draw(Engine->map->Neighbours[k]->Tiles[i][j]->icon);


				}

			}
		}
		for (int i = 0; i < Engine->unitList.size(); i++) {
			window.draw(Engine->unitList[i]->icon);
		}
		
		window.display();
		
	}
	return 0;
}