#include "Unit.h"
#include "Cell.h"
#include <iostream>
#include "Player.h"


Unit::Unit(int health, bool defense, Cell* cell2, Player* player):  health(health), defense(defense), cell(cell2), player(player)
{
}

Unit::Unit(const Unit& unit) : health(unit.health), defense(unit.defense), cell(unit.cell), player (unit.player)
{
	std::cout << "Unit::Unit(const Unit& unit)" << std::endl;
};

bool Unit::getDefense()const { return defense; }


std::string Unit::toString()
{
	std::string result = "";
	result = "<health>" + std::to_string(health);
	result += "<defence>" + std::to_string(defense);
	return result;
};

/*		std::string playerInfo = "Player#" + this->id;
		playerInfo += "\n";
		playerInfo += "Factories:\n";
		for (size_t i = 0; i < playerFactories.size(); i++)
		{
			playerInfo.append("factory#" + std::to_string(i) + " ");
			std::string factory_info = playerFactories.at(i)->toString();
			playerInfo.append(factory_info);
		}
		playerInfo += "Units:\n";
		for (size_t i = 0; i < playerUnits.size(); i++)
		{
			playerInfo.append(" unit#" + std::to_string(i));
			std::string unit = playerUnits.at(i)->toString();
			playerInfo.append(unit);
		}
		playerInfo += "END\n";

		return playerInfo;
		*/



Unit::~Unit()
{
	std::cout << "Unit::~Unit()" << std::endl;
}
int Unit::getHealth()
{
	return this->health;
}
void Unit::move(const int& forward, const int& up){}
//int Unit::getBonusAtack(Unit& unit) { return 10; };     //////////



int Unit::getDefenseBonus()
{
	int returnValue = 0;
	if (this->getDefense())
	{
		Cell::Landscape landscapeCell = this->cell->landscape;
		std::map<Cell::Landscape, int> defense = this->getBonusMapping().defenseBonus;
		auto it = defense.find(landscapeCell);

		if (it == defense.end())
		{
		}
		else
		{
			returnValue = it->second;
		}
	}
	return returnValue;
}

void Unit::setHealth(int health)
{
	this->health = health;
}



void Unit::printUnit()const { std::cout <<std::endl<< "Health= " << this->health << std::endl; };
//std::string Unit::whoAmI();



//void unitAttack(Unit&);
