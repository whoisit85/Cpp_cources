#include "Player.h"

unsigned int Player::id;

Player::Player()
{
}

Player::~Player()
{
}

unsigned int Player::getPlayerID()
{
	return 0;
}

std::string Player::toString()
{
	std::string result = "<PlayerID>" + std::to_string(id);
	result += "<PlayerUnits>";
	std::string units = "";
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		units = gameObjects.at(i)->toString();
	}
	//std::deque <GameObject*> gameObjects;
	result = result + units;

	return result;
}
