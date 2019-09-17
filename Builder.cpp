#include "Builder.h"
#include <iostream>
#include "FactoryUnit.hpp"
#include "FactoryEngineeringTroops.h"


Builder::Builder(int unitHelth, bool defense, Cell* cell, Player* player) : CivilUnit(unitHelth, defense, cell, player)
{
	std::cout << "Builder::Builder(int,bool,cell*,player*)" << std::endl;
};

Builder::~Builder()
{
}

template<typename T>
Factory<T>* Builder::buildAFactory() const
{
	Factory<T>* newFactory = new Factory<T>();
	return newFactory;
}

template<>
Factory<GroundTroops>* Builder::buildAFactory() const
{
	return (new Factory<GroundTroops>());
}

template<>
Factory<Builder>* Builder::buildAFactory() const
{
	return (new Factory<Builder>());
}

template<>
Factory<Medic>* Builder::buildAFactory() const
{
	return (new Factory<Medic>());
}


Unit::Bonus Builder::bonus =
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

std::string Builder::toString()
{
	std::string result = "<Builder>";
	result += Unit::toString();
	result += "<Cell>";
	result += this->cell->toString();
	result += "\n";
	return result;
};

Unit::Bonus Builder::getBonusMapping()
{
	return this->bonus;
}