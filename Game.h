#pragma once
#include <deque>
#include <vector>
#include "Player.h"
#include "Cell.h"
#include <fstream>
#include "Player.h"
#include "Builder.h"


#define SAVE_FILE_NAME "game.txt" 
//".//savegame//game"

class Game
{
private:
	std::deque<Player*> players;
	std::vector <std::string>& parseObjectFromString(std::string);
	std::deque <Player*> createPlayers(std::deque <std::vector<std::string>>& );
	void createObjectForPlayer(std::deque <std::vector<std::string>>& , Player *);

public:
	void addPlayer(Player*);
	void saveGametoFile(/*std::string*/);
	void loadGame(std::string);
};

