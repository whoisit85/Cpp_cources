#pragma once
#include <string>
#include "FactoryUnit.hpp"
#include "CivilUnit.h"
#include "Builder.h"


template<>
class Factory <Builder>
{
public:
	Factory() 
	{
		std::cout << "FactoryEngineeringTroops()" << std::endl;
	}
	~Factory() 
	{
		std::cout << "~FactoryEngineeringTroops()" << std::endl;
	}
	Builder* getUnit(const std::string& unitType, int health, int damage, bool defense, Cell* cell, Player* player)
	{
		Builder* unit = nullptr;
		if (unitType == "builder") { unit = new Builder(health, defense, cell, player); }

		return unit;
	}
	;
}
;
