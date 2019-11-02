#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::Move(int direction) {
	
	PC->move(direction);
}