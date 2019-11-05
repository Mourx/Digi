#include <vector>
#include <SFML/Graphics.hpp>
#include "UnitObject.h"
#include "MacroValues.h"
#include <boost/serialization/serialization.hpp>




int main() {

	init();
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	window.getSize();
	GameEngine* Engine = new GameEngine(window.getDefaultView());
	

	sf::Clock clock;
	
	
	
	while (window.isOpen())
	{
		sf::Time currentTime = clock.getElapsedTime();
		window.setView(Engine->camera);
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
		
		window.draw(Engine->player->PC->icon);
	
		
		window.display();
		
	}
	return 0;
}