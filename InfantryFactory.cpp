#include "InfantryFactory.h"
#include "Infantry.h"
#include "Unit.h"
#include <string>
#include <iostream>

InfantryFactory::InfantryFactory()
{
	std::cout << "InfantryFactory::InfantryFactory()" << std::endl;
}

InfantryFactory::~InfantryFactory()
{
	std::cout << "InfantryFactory::~InfantryFactory()" << std::endl;
}

Unit* InfantryFactory::getUnit(const std::string& unitType,int health, int damage,bool defense, Cell * cell)
{
	Unit* unit = nullptr;
	if (unitType == "infantry")
	{
		unit = new Infantry(health,damage, defense,cell);
	}
	return unit;
}