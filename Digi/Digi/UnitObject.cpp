#include "UnitObject.h"
#include "UIElement.h"

UnitObject::UnitObject(int UnitTypeID, GameEngine* Engine, int nodeX, int nodeY):GameObject(){
	engine = Engine;
	spriteIcon.loadFromFile("spritesheet.png", sf::IntRect(32, 0, 32, 32));
	icon.setTexture(spriteIcon);
	scaleX = 1;
	scaleY = 1;
	icon.setScale(scaleX, scaleY);
	for (int i = 0; i < 4; i++) {
		UIElement* bar = new UIElement(-1, engine);
		healthBars.push_back(bar);
		healthBars[i]->icon.setPosition(posX, posY - 10);	
	}
	healthBars[MINI_HEALTH_RED]->spriteIcon.loadFromFile("spritesheet.png", sf::IntRect(32, 32, 32, 32));
	healthBars[MINI_HEALTH_RED]->icon.setTexture(healthBars[0]->spriteIcon);
	healthBars[MINI_HEALTH_RED]->icon.setScale(scaleX, 0.25);
	healthBars[MINI_HEALTH_RED]->icon.setPosition(posX, posY - 10);

	healthBars[MINI_HEALTH_GREEN]->spriteIcon.loadFromFile("spritesheet.png", sf::IntRect(0, 32, 32, 32));
	healthBars[MINI_HEALTH_GREEN]->icon.setTexture(healthBars[1]->spriteIcon);
	healthBars[MINI_HEALTH_GREEN]->icon.setScale(scaleX, 0.25);
	healthBars[MINI_HEALTH_GREEN]->icon.setPosition(posX, posY - 10);

	healthBars[LARGE_HEALTH_RED]->spriteIcon.loadFromFile("spritesheet.png", sf::IntRect(32, 32, 32, 32));
	healthBars[LARGE_HEALTH_RED]->icon.setTexture(healthBars[2]->spriteIcon);
	healthBars[LARGE_HEALTH_RED]->icon.setScale(8, 32 / 32);
	healthBars[LARGE_HEALTH_RED]->icon.setPosition(200, 700);

	healthBars[LARGE_HEALTH_GREEN]->spriteIcon.loadFromFile("spritesheet.png", sf::IntRect(0, 32, 32, 32));
	healthBars[LARGE_HEALTH_GREEN]->icon.setTexture(healthBars[3]->spriteIcon);
	healthBars[LARGE_HEALTH_GREEN]->icon.setScale(8, 32 / 32);
	healthBars[LARGE_HEALTH_GREEN]->icon.setPosition(200, 700);
}

void UnitObject::animate() {
	if (sprite == 1) {
		spriteIcon.loadFromFile("spritesheet.png", sf::IntRect(64, 0, 32, 32));
		icon.setTexture(spriteIcon);
		sprite = 2;
	}
	else {
		spriteIcon.loadFromFile("spritesheet.png", sf::IntRect(32, 0, 32, 32));
		icon.setTexture(spriteIcon);
		sprite = 1;
	}
	
}

int UnitObject::getValue(int whichValue) {
	switch (whichValue) {
	case VALUE_HEALTH:
		return health;
	case VALUE_SPEED:
		return speed;
	case VALUE_ARMOUR:
		return armour;
	default:
		return -9999999;
	}
}



void UnitObject::onRightClick(int x,int y, sf::Time time) {
	

	printf("clicky");
}


void UnitObject::move(sf::Time time) {
	
}

void UnitObject::update(sf::Time time) {		
	if (time.asMilliseconds() - animateTime >= 200) {
		animate();
		animateTime = time.asMilliseconds();
	}

}

float getDistance(int x, int y, int targX, int targY) {
	return sqrt(pow((targX - x), 2) + pow((targY - y), 2));
}

float getDistance(Node* start, Node* target) {
	return sqrt(pow((target->x - start->x), 2) + pow((target->y - start->y), 2));
}


