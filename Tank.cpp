#include "Tank.h"
#include <iostream>
//
//Tank::Tank()
//{
//	std::cout << "Tank::Tank()" << std::endl;
//}
Tank::Tank(int unitHelth, int unitDamage,bool defense, Cell * cell, Player* player) : GroundTroops(unitHelth, unitDamage, defense,cell, player)

{}
Tank::~Tank()
{
	std::cout << "Tank::~Tank()" << std::endl;
}

Unit::Bonus Tank::bonus =
{
	{
				{Cell::Landscape::field,60},
				{Cell::Landscape::water,0},
				{Cell::Landscape::sand,50},
				{Cell::Landscape::forest,-5},
				{Cell::Landscape::swamp,0},
				{Cell::Landscape::mount,-5}
	},

	{
		{Cell::Landscape::field,100},
		{Cell::Landscape::water,0},
		{Cell::Landscape::sand,20},
		{Cell::Landscape::forest,40},
		{Cell::Landscape::swamp,10},
		{Cell::Landscape::mount,40}
	}
};

std::string Tank::toString()
{
	std::string result = "Tank,";
	result += Unit::toString();
	result += "Cell,";
	result += this->cell->toString();
	result += "damage,";
	result += std::to_string(this->damage);
	result += "\n";
	return result;
}

Unit::Bonus Tank::getBonusMapping()
{
	return this->bonus;
}







void Tank::move(const int& forward, const int& up)
{
	std::cout << "Tank: BRRRR-BRRRR-RRRRR!"<<std::endl;
	//forwardCoordinates += forward;
	//upCoordinates += up;
}
