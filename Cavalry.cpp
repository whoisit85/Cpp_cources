#include "Cavalry.h"
#include <iostream>

Unit::Bonus Cavalry::bonus =
{
	{
			{Cell::Landscape::field,20},
			{Cell::Landscape::water,-1},
			{Cell::Landscape::sand,10},
			{Cell::Landscape::forest,0},
			{Cell::Landscape::swamp,-8},
			{Cell::Landscape::mount,5}
	},

	{
			{Cell::Landscape::field,15},
			{Cell::Landscape::water,0},
			{Cell::Landscape::sand,10},
			{Cell::Landscape::forest,4},
			{Cell::Landscape::swamp,8},
			{Cell::Landscape::mount,7}
	}
};

std::string Cavalry::toString()
{
	std::string result = "Cavalry,";
	result += Unit::toString();
	result += "Cell,";
	result += this->cell->toString();
	result += ",";	
	result += "damage,";
	result += std::to_string(this->damage);
	result += "\n";
	return result;
}

Unit::Bonus Cavalry::getBonusMapping()
{
	return this->bonus;
}

//Cavalry::Cavalry()
//{
//	std::cout << "Cavalry::Cavalry()" << std::endl;
//}

Cavalry::Cavalry(GroundTroops& unit) : GroundTroops(unit)
{
	std::cout << "Cavalry::Cavalry(Unit& unit)" << std::endl;
};

Cavalry::Cavalry(int health, int damage, bool defense,Cell * cell, Player* player) : GroundTroops(health, damage,defense, cell, player)
{
   std::cout << "Cavalry::Cavalry(int health, int damage, cell*, player*)" << std::endl;
};

Cavalry::~Cavalry()
{
	std::cout << "Cavalry::~Cavalry()" << std::endl;
}

void Cavalry::move(const int& forward, const int& up)
{
	std::cout << "Cavalry: tuk-tuk-tuk!" << std::endl;
	//forwardCoordinates += forward;
	//upCoordinates += up;
}






//virtual getBonusMapping();

//std::string Cavalry::whoAmI() { return "cavalry"; };
