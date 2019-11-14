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
		icon.setTexture(*texturePlayer[0]);
		sprite = 2;
	}
	else {
		icon.setTexture(*texturePlayer[1]);
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

void UnitObject::setShift(int direction) {
	shiftDirection = direction;
	bShiftRoom = true;
}

void UnitObject::move(int direction) {
	currentNode = engine->map->Tiles[(int)icon.getPosition().y / 32][(int)icon.getPosition().x / 32];
	getNeighbourNodes();
	
	if (!bMoving){
		targetNode = adjacentNodes[direction];
		if (targetNode->bPathable) {
			switch (direction) {
			case DIRECTION_UP:
				dirY = -1;
				dirX = 0;
				diffY = -32;
				break;
			case DIRECTION_RIGHT:
				dirY = 0;
				dirX = 1;
				diffX = 32;
				break;
			case DIRECTION_DOWN:
				dirY = 1;
				dirX = 0;
				diffY = 32;
				break;
			case DIRECTION_LEFT:
				dirY = 0;
				dirX = -1;
				diffX = -32;
				break;
			}
			bMoving = true;
			startTime.Zero;
			if (targetNode->bNewRoom) {
				setShift(direction);
			}
		}
	}
}

void UnitObject::update(sf::Time time) {
	
	if (bMoving) {

		if (time.asMilliseconds() - animateTime >= 200) {
			animate();
			animateTime = time.asMilliseconds();
		}
		if (startTime.asMilliseconds() == 0) {
			startTime = time;
		}
		int diff = time.asMilliseconds() - startTime.asMilliseconds();
		if (diff % 1 == 0) {
			icon.setPosition(icon.getPosition().x + moveSpeed * dirX, icon.getPosition().y + moveSpeed * dirY);
			diffY -= moveSpeed * dirY;
			diffX -= moveSpeed * dirX;
		}
		if (checkArrived()) {
			if (bShiftRoom) {
				switch (shiftDirection) {
				case DIRECTION_UP:
					icon.setPosition(icon.getPosition().x, icon.getPosition().y+1024);
					break;
				case DIRECTION_RIGHT:
					icon.setPosition(icon.getPosition().x-1280, icon.getPosition().y);
					break;
				case DIRECTION_DOWN:
					icon.setPosition(icon.getPosition().x, icon.getPosition().y - 1024);
					break;
				case DIRECTION_LEFT:
					icon.setPosition(icon.getPosition().x+1280, icon.getPosition().y);
					break;
				}
				engine->LoadNewRoom(0);
				bShiftRoom = false;
			}
			else {
				icon.setPosition(targetNode->icon.getPosition());
			}
			currentNode = engine->map->Tiles[(int)icon.getPosition().y / 32][(int)icon.getPosition().x / 32];
			targetNode = NULL;
			getNeighbourNodes();
			bMoving = false;
		}
	}

}

bool UnitObject::checkArrived() {
	if (abs(diffX) <= 0 && abs(diffY) <= 0) {
		return true;
	}
	else {
		return false;
	}
}

float getDistance(int x, int y, int targX, int targY) {
	return sqrt(pow((targX - x), 2) + pow((targY - y), 2));
}

float getDistance(Node* start, Node* target) {
	return sqrt(pow((target->x - start->x), 2) + pow((target->y - start->y), 2));
}

void UnitObject::getNeighbourNodes() {
	adjacentNodes.clear();
	Node* temp = engine->getAdjacentTile(currentNode, DIRECTION_UP);
	adjacentNodes.push_back(temp);
	temp = engine->getAdjacentTile(currentNode, DIRECTION_RIGHT);
	adjacentNodes.push_back(temp);
	temp = engine->getAdjacentTile(currentNode, DIRECTION_DOWN);
	adjacentNodes.push_back(temp);
	temp = engine->getAdjacentTile(currentNode, DIRECTION_LEFT);
	adjacentNodes.push_back(temp);
}
