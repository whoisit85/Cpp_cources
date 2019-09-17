/*
#include <string>
#include <iostream>
#include "MilitaryUnit.h"
#include "Cavalry.h"
#include "Infantry.h"
#include "FactoryGroundTroops.h"
#include "Player.h"

Factory<MilitaryUnit>::Factory()
{
	std::cout << "Factory<MilitaryUnit>::Factory()" << std::endl;
}

Factory<MilitaryUnit>::~Factory()
{
	std::cout << "~Factory<MilitaryUnit>::Factory()" << std::endl;

}


MilitaryUnit* Factory<MilitaryUnit>::getUnit(const std::string& unitType, int health, int damage, bool defense, Cell* cell, Player * player)
{
	MilitaryUnit* unit = nullptr;
	if (unitType == "infantry")	{unit = new Infantry(health, damage, defense, cell, player); }
	if (unitType == "cavalry") {unit = new Cavalry(health, damage, defense, cell, player);}

	return unit;
}

*/
