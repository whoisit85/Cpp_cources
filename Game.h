#pragma once
#include <deque>
#include "Player.h"
#include "Cell.h"
#include <fstream>

#define SAVE_FILE_NAME "game.txt" 
//".//savegame//game"

class Game
{
private:
	std::deque<Player*> players;

public:
	void addPlayer(Player*);
	void saveGametoFile(/*std::string*/);
};

