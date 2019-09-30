#include "Game.h"
#include <deque>
#include <vector>
#include <iostream>
//#include <fstream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include "Player.h"

std::string currentTimeToString()
{
	auto rawtime = std::chrono::system_clock::now();
	auto inTime = std::chrono::system_clock::to_time_t(rawtime);
	std::tm  buffer;
	localtime_s(&buffer, &inTime);
	std::string result = "";
	result += std::to_string(buffer.tm_year + 1900) + "." + std::to_string(buffer.tm_mon + 1) + "." + std::to_string(buffer.tm_mday) + "_" + std::to_string(buffer.tm_hour) + "_" + std::to_string(buffer.tm_min);
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
	std::string fileName = file;
//	std::string fileName = "";
/*	std::cout << "Enter file name for save: ";
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
		std::cout << "PROPOSED FILE NAME = " << fileName;
	}
	*/
	//////////////////////////////////////////////////

	std::ofstream fileStream (fileName);
	if (fileStream.is_open()) 
	{
		for (size_t i = 0; i < this->players.size(); i++)
		{
			Player* player = this->players.at(i);
			fileStream << player->toString();
		}
	}
	fileStream.close();
	return;
}

void Game::loadGame(std::string fileName)
{
	std::ifstream file(fileName);
	std::string buffer;

	if (file.is_open()) 
	{
		std::cout << "READ FROM FILE: " << fileName << std::endl;
		while (std::getline(file, buffer/*, ',' */)) 
		{
			//std::cout << buffer << std::endl;
			parseObjectFromString(buffer);
		}
	}
	file.close();
}


Player* Game::parseObjectFromString(std::string string)
{
	Player * player = nullptr;
	std::vector <std::string> tokens;
	char delim = ',';
	size_t start = 0;
	size_t end = 0;
	while ((start = string.find_first_not_of(delim, end))!= std::string::npos)
	{
		end = string.find(delim, start);
		tokens.push_back(string.substr(start, end - start));
	}
	/*for (size_t i = 0; i < tokens.size(); i++)
	{

		std::cout << tokens.at(i) << std::endl;
	}*/
	GameObject * gameObject = createObject(tokens);

	return player;
}

GameObject* Game::createObject(std::vector<std::string>& tok)
{
	GameObject* gameObject = nullptr;
	if (strcmp("Player", tok[0].c_str())) 
	{
		Player* player = new Player();
		player->setPlayerID(atoi(tok[1].c_str()));
	}


	return gameObject;
}
