#pragma once
#include <string>
#include "Cell.h"
#include "Player.h"

class Player;

template <typename T>
class Factory
{
public:
	Factory()
	{
		std::cout << "Factory::Factory()" << std::endl;
	}

	~Factory()
	{
		std::cout << "Factory::~Factory()" << std::endl;
		//std::for_each(departments.begin(), departments.end(), [](Factory * factory) { delete factory; });
	}

	T* getUnit(const std::string& unitType, int health, int damage, bool defense, Cell* cell, Player * player)
	{
		T* unit = getUnit(unitType, health, damage, defense, cell, player);

		return unit;
	}


	//void addDepartment(Factory*);
	//Factory<GroundTroops>* buildAFactory() const;
};