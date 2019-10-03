#include "Game.h"
#include <deque>
#include <vector>
#include <iostream>
//#include <fstream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include "CreationtBuilder.h"
#include"FactoryUnit.hpp"

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
std::vector <std::string> & Game::parseObjectFromString(std::string string)
{
	std::vector <std::string> * tokens = new std::vector <std::string>();
	char delim = ',';
	size_t start = 0;
	size_t end = 0;
	while ((start = string.find_first_not_of(delim, end))!= std::string::npos)
	{
		end = string.find(delim, start);
		tokens->push_back(string.substr(start, end - start));
	}
	
	return *tokens;
}


void Game::createObjectForPlayer(std::deque <std::vector<std::string>>& dek, Player * player) 
{
	std::vector <std::string> vec = dek.front();
	if ( vec[0] == "Builder" )
	{
		int health = atoi(vec[2].c_str());
		bool defence = (vec[4] == "0" ? false : true);
		Cell* cell = new Cell(Cell::field, { 1, 1 });

		Builder* unit = new Builder(health, defence, cell, player); //Builder,health,100,defence,0,Cell,Landscape,field,point,1,1
		dek.pop_front();
	}
	else if (vec[0] == "Infantry")
	{
		int health = atoi(vec[2].c_str());
		int damage = atoi(vec[12].c_str());
		bool defence = (vec[4] == "0" ? false : true);
		Cell* cell = new Cell(Cell::field, { 1, 1 });

		Infantry* unit = new Infantry(health, damage, defence, cell, player); //Infantry, health, 32, defence, 1, Cell, Landscape, field, point, 1, 1, damage, 88

		dek.pop_front();
	}
	else if (vec[0] == "Cavalry")
	{
		int health = atoi(vec[2].c_str());
		int damage = atoi(vec[12].c_str());
		bool defence = (vec[4] == "0" ? false : true);
		Cell* cell = new Cell(Cell::field, { 1, 1 });

		Cavalry* unit = new Cavalry(health, damage, defence, cell, player); //Infantry, health, 32, defence, 1, Cell, Landscape, field, point, 1, 1, damage, 88

		dek.pop_front();
	}
	else if (vec[0] == "Tank")
	{
		int health = atoi(vec[2].c_str());
		int damage = atoi(vec[12].c_str());
		bool defence = (vec[4] == "0" ? false : true);
		Cell* cell = new Cell(Cell::field, { 1, 1 });

		Tank* unit = new Tank(health, damage, defence, cell, player); //Infantry, health, 32, defence, 1, Cell, Landscape, field, point, 1, 1, damage, 88

		dek.pop_front();
	}
	else if (vec[0] == "Factory{Builder}")
	{
		Cell* cell = new Cell(Cell::field, { 1, 1 });
		Factory <Builder>* factory = new Factory <Builder>(cell);
		dek.pop_front();
	}
	else if (vec[0] == "Factory{MilitaryUnit}")
	{
		Cell* cell = new Cell(Cell::field, { 1, 1 });
		Factory <MilitaryUnit>* factory = new Factory <MilitaryUnit>(cell);
		dek.pop_front();
	}
	else if (vec[0] == "Factory{Medic}")
	{
		Cell* cell = new Cell(Cell::field, { 1, 1 });
		Factory <Medic>* factory = new Factory <Medic>(cell);
		dek.pop_front();
	}
}

std::deque <Player*> Game::createPlayers(std::deque <std::vector<std::string>>& dek)
{
		

	Player* player = nullptr;
	if ("PlayerID" == dek[0].at(0)) //strings are equal 
	{
		while (!dek.empty())
		{
			player = new Player();
			player->setPlayerID(atoi(dek[0].at(1).c_str()));
			dek.pop_front();
			while (!dek.empty() && "PlayerID" != dek[0].at(0))
			{
				Game::createObjectForPlayer(dek, player);
			}
		}
	}
	else 
	{
		std::cerr << "ERROR READING FILE! FILE CORRUPTED!" << std::endl;
	}
	players.push_back(player);
	return players;
}


void Game::loadGame(std::string fileName)
{
	std::ifstream file(fileName);
	std::string buffer;

	//clear players list
	//if (!this->players.empty())
	//{
	//	for (size_t i = 0; i < players.size(); i++)
	//	{
	//		delete players[i];
	//	}
	//	players.clear();
	//}

	if (file.is_open()) 
	{
		std::deque <std::vector <std::string>> lines;
		std::cout << "READ FROM FILE: " << fileName << std::endl;
		std::vector <std::string> parsedLine;

		while (std::getline(file, buffer)) 
		{
			parsedLine = Game::parseObjectFromString(buffer);
			lines.push_back(parsedLine);
		}
		Game::createPlayers(lines); 

	}
	file.close();
}


