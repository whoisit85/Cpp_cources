#include "Medic.h"
#include<iostream>

Medic::Medic(int unitHelth, bool defense, Cell* cell, Player* player) : CivilUnit(unitHelth, defense, cell, player)
{
	std::cout << "	Medic(int, bool, Cell*, Player *)" << std::endl;
}


Medic::~Medic()
{
	std::cout << "~Medic(int, bool, Cell*)" << std::endl;

}

//void Medic::treatment(Unit* unit)
//{
//	unit->setHealth(15);
//}


Unit::Bonus Medic::bonus =
{
	{
	{Cell::Landscape::field,0},

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

std::string Medic::toString()
{
	std::string result = "<Medic>";
	result += Unit::toString();
	result += "<Cell>";
	result += this->cell -> toString();
	result += "\n";
	return result;
};


Unit::Bonus Medic::getBonusMapping()
{
	return this->bonus;
}
