#include <iostream>
#include "Medic.h"
#include "FactoryMedic.h"


Factory<Medic>::Factory()
{
	std::cout << "Factory<Medic>::Factory()" << std::endl;

}
Factory<Medic>::~Factory()
{
	std::cout << "~Factory<Medic>::Factory()" << std::endl;

}

Medic* Factory<Medic>::getUnit(const std::string& unitType, int health, int damage, bool defense, Cell* cell, Player* player)
{
	Medic* unit = nullptr;
	if (unitType == "medic") { unit = new Medic(health, defense, cell, player); }

	return unit;
}

