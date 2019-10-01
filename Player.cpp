#include "Player.h"
#include <iostream>

unsigned int Player::id;

Player::Player()
{
	++id;
	std::cout << "Player()" << id << std::endl;
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
	std::string result = "PlayerID," + std::to_string(id);
	//result += "<PlayerUnits>";
	result += "\n";
	std::string units = "";
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		result += gameObjects.at(i)->toString();
	}


	return result;
}

void Player::addGameObject(GameObject* obj)
{
	this->gameObjects.push_back(obj);
	return;
}

std::deque<GameObject*> Player::getGameObjects()
{
	return this->gameObjects;
}

void Player::setPlayerID(unsigned int newID)
{
	id = newID;
}
