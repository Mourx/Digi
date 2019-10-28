#include <vector>
#include <SFML/Graphics.hpp>
#include "UnitObject.h"

sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
GameEngine* Engine = new GameEngine();


int main() {

	sf::Clock clock;
	UnitObject* Soldier = new UnitObject(1, Engine, 24, 16);
	Engine->AddUnit(Soldier);
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
		window.draw(Soldier->icon);
		window.display();
		
	}
	return 0;
}