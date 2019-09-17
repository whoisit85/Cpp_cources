#include"TankFactory.h"
#include <string>
#include <iostream>

TankFactory::TankFactory()
{
	std::cout << "CavalryFactory::CavalryFactory()" << std::endl;
}

TankFactory::~TankFactory()
{
	std::cout << "TankFactory::~TankFactory()" << std::endl;
}


MilitaryUnit* TankFactory::getUnit(const std::string& unitType,int health,int damage,bool defense,Cell* cell)
{
	MilitaryUnit* unit = nullptr;
	if (unitType == "tank")
	{
		unit = new Tank(health,damage, defense,cell);
	}
	return unit;
}