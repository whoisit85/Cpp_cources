#include "MilitaryUnit.h"
#include<iostream>

MilitaryUnit::MilitaryUnit(int unitHelth, int unitDamage, bool defense, Cell* cell, Player* player) : Unit(unitHelth, defense, cell, player),damage(unitDamage)
{
	std::cout << "MilitarylUnit(int, int, bool, Cell*, Player *)" << std::endl;
}

MilitaryUnit::~MilitaryUnit()
{
}
int MilitaryUnit::getAttackBonus()
{
	int returnValue = 0;
	Cell::Landscape landscapeCell = this->cell->landscape;
	std::map<Cell::Landscape, int> attack = this->getBonusMapping().attackBonus;
	auto it = attack.find(landscapeCell);

	if (it == attack.end())
	{
	}
	else
	{
		returnValue = it->second;
	}
	return returnValue;
}

void MilitaryUnit::attack(Unit& enemy)
{
	enemy.setHealth(enemy.getHealth()- (this->damage + this->getAttackBonus() - enemy.getDefenseBonus()));
};

std::string MilitaryUnit::toString()
{
	
	return "";
};
