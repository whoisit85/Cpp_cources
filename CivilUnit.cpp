#include "CivilUnit.h"
#include<iostream>



CivilUnit::CivilUnit(int unitHelth, bool defense, Cell* cell, Player* player) : Unit(unitHelth, defense, cell, player)
{
}

CivilUnit::~CivilUnit()
{
}

std::string CivilUnit::toString()
{
	return "";
}


