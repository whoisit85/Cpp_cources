#include "Game.h"
#include <deque>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>

std::string currentTimeToString()
{
	auto rawtime = std::chrono::system_clock::now();
	auto inTime = std::chrono::system_clock::to_time_t(rawtime);
	std::tm  buffer;
	localtime_s(&buffer, &inTime);
	std::string result = "";
	result += std::to_string(buffer.tm_year + 1900) + "." + std::to_string(buffer.tm_mon + 1) + "." + std::to_string(buffer.tm_mday) + "_" + std::to_string(buffer.tm_hour) + ":" + std::to_string(buffer.tm_min);
	return result;
}

void Game::addPlayer(Player* player)
{
	this->players.push_back(player);
	return;
}

void Game::saveGametoFile(/*std::string fileName = SAVE_FILE_NAME*/ )
{

	std::string file = SAVE_FILE_NAME;
	std::string fileName = "";
	std::cout << "Enter file name for save: ";
	std::getline(std::cin, fileName);
	if(fileName.empty())
	{
		fileName = file;
	}
	else 
	{
		fileName += ".txt";
	}
	
	std::cout << "Add current time?   Yes (enter 1): ";
	int choice = 0;
	std::cin >> choice;
	if (choice)
	{
		fileName = currentTimeToString()+ fileName;
	}
	//////////////////////////////////////////////////

	std::ofstream fileStream (fileName);
	if (fileStream.is_open()) 
	{
		for (size_t i = 0; i < this->players.size(); i++)
		{
			Player* player = this->players.at(i);
			fileStream << player->toString();
			/*std::deque <GameObject*> playerObjects = player->getGameObjects();
			for (size_t k = 0; k < playerObjects.size(); k++)
			{
				fileStream << playerObjects.at(k)->toString();
			}
			*/
		}
	}
	fileStream.close();
	return;
}

