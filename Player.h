#pragma once
#include <string>
#include <deque>
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
	void addGameObject(GameObject* );
	std::deque <GameObject*> getGameObjects();

private:
	std::deque <GameObject*> gameObjects;

};
