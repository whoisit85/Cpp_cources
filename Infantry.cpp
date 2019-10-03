#include "Infantry.h"
#include <iostream>
//
//Infantry::Infantry()
//{
//	std::cout << "Infantry::Infantry()" << std::endl;
//}

Infantry::Infantry(GroundTroops& unit):GroundTroops(unit)
{
}

Infantry::Infantry(int unitHelth, int unitDamage, bool defense, Cell * cell, Player* player) : GroundTroops(unitHelth, unitDamage,defense, cell, player)
{
	std::cout << "Infantry::Infantry(health=" <<unitHelth << ",damage=" << unitDamage << ",defense=" << defense << ",Cell*, Player *)" << std::endl;
};

Infantry::~Infantry()
{
	std::cout << "Infantry::~Infantry()" << std::endl;
}

void Infantry::move(const int& forward, const int& up)
{
	std::cout << "Infantry: Go-Go-Go!" << std::endl;
}

Unit::Bonus Infantry::bonus =
{
	{
	{Cell::Landscape::field,5},
	{Cell::Landscape::water,-3},
	{Cell::Landscape::sand,1},
	{Cell::Landscape::forest,10},
	{Cell::Landscape::swamp,-3},
	{Cell::Landscape::mount,8}
	},

	{
	{Cell::Landscape::field,10},
	{Cell::Landscape::water,-5},
	{Cell::Landscape::sand,3},
	{Cell::Landscape::forest,20},
	{Cell::Landscape::swamp,0},
	{Cell::Landscape::mount,15}
	}
};

std::string Infantry::toString()
{
	std::string result = "Infantry,";
	result += Unit::toString();
	result += "Cell,";
	result += this->cell->toString();
	result += ",";
	result += "damage,";
	result += std::to_string(this->damage);
	result += "\n";
	return result;
};



Unit::Bonus Infantry::getBonusMapping()
{
	return this->bonus;
}


//std::string Infantry::whoAmI() { return "infantry"; };

