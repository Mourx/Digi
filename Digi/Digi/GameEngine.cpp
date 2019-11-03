#include "GameEngine.h"


GameEngine::GameEngine(sf::View window) {
	camera = window;
	for (int i = 0; i < GRID_ROWS; i++) {
		std::vector<Node*> vector;
		for (int j = 0; j < GRID_COLUMNS; j++) {
			vector.push_back(new Node());
		}
	
	}
	camera.zoom(1);
	camera.setCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	camera.setSize(600, 600);
	
	UnitObject* Soldier = new UnitObject(1, this, 24, 16);
	Soldier->setPosition(576, 32);
	player = new Player();
	player->PC = Soldier;
	input = new InputHandler(this);
	camera.setCenter(player->PC->icon.getPosition());

}

void GameEngine::ConvertToNodes(int grid[100][100], std::vector<std::vector<Node*>> nodes) {
	for (int i = 0; i < GRID_ROWS; i++) {
		for (int j = 0; j < GRID_COLUMNS; j++) {
			nodes[i][j]->travelCost = grid[i][j];
			nodes[i][j]->x = j * 8;
			nodes[i][j]->y = i * 8;
			if (i > 0) AssignAdjacent(DIRECTION_UP, nodes[i][j], nodes[i - 1][j]); else nodes[i][j]->Adjacent[DIRECTION_UP] = new Node(); // Up
			if (j < GRID_COLUMNS - 1) AssignAdjacent(DIRECTION_RIGHT, nodes[i][j], nodes[i][j + 1]); else nodes[i][j]->Adjacent[DIRECTION_RIGHT] = new Node(); // Right
			if (i < GRID_ROWS - 1) AssignAdjacent(DIRECTION_DOWN, nodes[i][j], nodes[i + 1][j]); else nodes[i][j]->Adjacent[DIRECTION_DOWN] = new Node(); // Down
			if (j > 0) AssignAdjacent(DIRECTION_LEFT, nodes[i][j], nodes[i][j - 1]); else nodes[i][j]->Adjacent[DIRECTION_LEFT] = new Node(); // Left
		}
	}
}

void GameEngine::AssignAdjacent(int Direction, Node* node, Node* next) {
	if (next != nullptr) {
		node->Adjacent[Direction] = next;
	}
	else {
		node->Adjacent[Direction] = nullptr;
	}
}


void GameEngine::AddUnit(GameObject* unit) {
	unitList.push_back(unit);
}

void GameEngine::Update(sf::Time time) {
	for (int i = 0; i < unitList.size(); i++) {
		unitList[i]->update(time);
	}
	player->PC->update(time);
	input->checkKeyboard();
	camera.setCenter(player->PC->icon.getPosition());
}

void GameEngine::LoadNewRoom(int id) {
	map->LoadMap(id);
	map->LoadNeighbours(id);
}

Node* GameEngine::getAdjacentTile(Node* startNode,int direction) {
	switch (direction) {
	case DIRECTION_UP:
		if ((int)startNode->y <= 0) {
			
			Node* temp = map->Neighbours[1]->Tiles[31][(int)startNode->x / 32];
			temp->bNewRoom = true;
			return temp;
		}
		else {
			return map->Tiles[-1 + (int)startNode->y / 32][(int)startNode->x / 32];
		}
	case DIRECTION_RIGHT:
		if ((int)startNode->x >= 1248) {
			
			Node* temp = map->Neighbours[4]->Tiles[(int)startNode->y/32][0];
			temp->bNewRoom = true;
			return temp;
		}
		else {
			return map->Tiles[(int)startNode->y / 32][1+(int)startNode->x / 32];

		}
	case DIRECTION_DOWN:
		if ((int)startNode->y >= 992) {
			
			Node* temp = map->Neighbours[6]->Tiles[0][(int)startNode->x / 32];
			temp->bNewRoom = true;
			return temp;
		}
		else {
			return map->Tiles[1 + (int)startNode->y / 32][(int)startNode->x / 32];
		}
	case DIRECTION_LEFT:
		if ((int)startNode->x == 0) {
			
			Node* temp = map->Neighbours[1]->Tiles[(int)startNode->y / 32][39];
			temp->bNewRoom = true;
			return temp;
		}
		else {
			return map->Tiles[(int)startNode->y / 32][-1 + (int)startNode->x / 32];
		}
	}
}