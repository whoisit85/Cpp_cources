#include "Unit.h"
#include "CavalryFactory.h"
#include "Cavalry.h"
#include <string>
#include <iostream>

CavalryFactory::CavalryFactory()
{
	std::cout << "CavalryFactory::CavalryFactory()" << std::endl;
}

CavalryFactory::~CavalryFactory()
{
	std::cout << "CavalryFactory::~CavalryFactory()" << std::endl;
}

Unit* CavalryFactory::getUnit(const std::string& unitType, int health,int damage,bool defense, Cell * cell)
{
	return unitType == "cavalry"? new Cavalry(health,damage,defense, cell): nullptr;
}