#pragma once
#include <deque>
#include <vector>
#include "Player.h"
#include "Cell.h"
#include <fstream>

#define SAVE_FILE_NAME "game.txt" 
//".//savegame//game"

class Game
{
private:
	std::deque<Player*> players;
	Player* parseObjectFromString(std::string);
	GameObject* createObject(std::vector<std::string>& tok);

public:
	void addPlayer(Player*);
	void saveGametoFile(/*std::string*/);
	void loadGame(std::string);
};

