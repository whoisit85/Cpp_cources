#pragma once
#include <string>
#include <iostream>
#include "Cell.h"
#include "Player.h"
//#include "Builder.h"
#include "Cavalry.h"
#include "Infantry.h"
#include "Medic.h"
#include "Tank.h"
//#include "CivilUnit.h"
//#include "MilitaryUnit.h"
#include "CreationtBuilder.h"

//class Builder;
//class Player;

template <typename T>
class Factory
{
public:
	Factory()
	{
		std::cout << "Factory::Factory()" << std::endl;
	}

	~Factory()
	{
		std::cout << "Factory::~Factory()" << std::endl;
		//std::for_each(departments.begin(), departments.end(), [](Factory * factory) { delete factory; });
	}

	T* getUnit(const std::string& unitType, int health, int damage, bool defense, Cell* cell, Player * player)
	{
		T* unit = getUnit(unitType, health, damage, defense, cell, player);

		return unit;
	}


	//void addDepartment(Factory*);
	//Factory<GroundTroops>* buildAFactory() const;
};
//
//template<>
//class Factory <Builder>
//{
//public:
//	Factory()
//	{
//		std::cout << "FactoryEngineeringTroops()" << std::endl;
//	}
//	~Factory()
//	{
//		std::cout << "~FactoryEngineeringTroops()" << std::endl;
//	}
//	Builder* getUnit(const std::string& unitType, int health, int damage, bool defense, Cell* cell, Player* player)
//	{
//		Builder* unit = nullptr;
//		CreationBuilder creationBuilder;
//		if (unitType == "builder") { unit = creationBuilder.creationBuilder(health, defense, cell, player); }
//
//		return unit;
//	};
//};

//template<>
//class Factory<MilitaryUnit>
//{
//public:
//	Factory() { std::cout << "Factory<MilitaryUnit>::Factory()" << std::endl; };
//	~Factory() { std::cout << "~Factory<MilitaryUnit>::Factory()" << std::endl; };
//	MilitaryUnit* getUnit(const std::string& unitType, int health, int damage, bool defense, Cell* cell, Player* player)
//	{
//		MilitaryUnit* unit = nullptr;
//		if (unitType == "infantry") { unit = new Infantry(health, damage, defense, cell, player); }
//		if (unitType == "cavalry") { unit = new Cavalry(health, damage, defense, cell, player); }
//
//		return unit;
//	};
//};
//
//template<>
//class Factory<Medic>
//{
//    public:
//		Factory() { std::cout << "Factory<MilitaryUnit>::Factory()" << std::endl; };
//		~Factory() { std::cout << "~Factory<MilitaryUnit>::Factory()" << std::endl; };
//	Medic* getUnit(const std::string& unitType, int health, int damage, bool defense, Cell* cell, Player* player)
//	{
//		Medic* unit = nullptr;
//		if (unitType == "medic") { unit = new Medic(health, defense, cell, player); }
//
//		return unit;
//	}
//	};


