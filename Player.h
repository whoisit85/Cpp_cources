#pragma once
#include <string>
#include <deque>
#include "Builder.h"
#include "FactoryUnit.hpp"
#include "GameObject.h"

class Player : public GameObject
{
public:
	static unsigned int id;
	Player();
	~Player();
	unsigned int getPlayerID();
	std::string toString() override;
	//makeMove();
	//skipTurn();
private:
	std::deque <GameObject*> gameObjects;

};