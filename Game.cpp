#include "Game.h"
#include <deque>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>



void Game::addPlayer(Player* player)
{
	this->addPlayer(player);
	return;
}

void Game::saveGametoFile(/*std::string fileName = SAVE_FILE_NAME*/ )
{

	std::string file = SAVE_FILE_NAME;
	file +=  ".txt";
	
	/*auto t = std::time(nullptr);
	struct tm * timeinfo;
	auto tm = localtime_s(timeinfo, &t);
	std::ostringstream oss;
	oss << std::put_time(tm, "%Y-%m-%d_%H-%M-%S");
	file += oss.str();
	*/

	std::ofstream fileStream (file);
	if (fileStream.is_open()) 
	{
		for (size_t i = 0; i < this->players.size(); i++)
		{
			Player* player = this->players.at(i);
			fileStream << player->toString();
			std::deque <GameObject*> playerObjects = player->getGameObjects();
			for (size_t k = 0; k < playerObjects.size(); k++)
			{
				fileStream << playerObjects.at(k)->toString();
			}
		}
	}
	fileStream.close();
	return;
}
