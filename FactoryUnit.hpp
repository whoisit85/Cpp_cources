#pragma once
#include <string>
#include <iostream>
#include "Cell.h"
#include "Player.h"
#include "Cavalry.h"
#include "Infantry.h"
#include "Medic.h"
#include "Tank.h"
#include "CreationtBuilder.h"

template <typename T>
class Factory : public GameObject
{
public:
	Cell* cell;
	Factory(Cell* cell) : cell(cell)
	{
		std::cout << "Factory::Factory()" << std::endl;
	}

	~Factory()
	{
		std::cout << "Factory::~Factory()" << std::endl;
	}

	T* getUnit(const std::string& unitType, int health, int damage, bool defense, Cell* cell, Player* player)
	{
		T* unit = getUnit(unitType, health, damage, defense, cell, player);
		player->addGameObject(unit);
		return unit;
	}
	std::string toString() override
	{
		std::string result = "<Factory{T}>";
		result += "<Cell>";
		result += this->cell->toString();
		result += "\n";
		return result;
	};
};

	template<>
	class Factory <Builder>  : public GameObject
	{
	public:
		Cell* cell;
		Factory(Cell * cell) : cell(cell)
		{
			std::cout << "FactoryEngineeringTroops()" << std::endl;
		}
		~Factory()
		{
			std::cout << "~FactoryEngineeringTroops()" << std::endl;
		}
		Builder* getUnit(const std::string& unitType, int health, int damage, bool defense, Cell* cell, Player* player)
		{
			Builder * unit = nullptr;
			CreationBuilder creationBuilder;
			
			if (unitType == "builder") { unit = creationBuilder.creationBuilder(health, defense, cell, player); }
			//player->addGameObject(unit);
			return unit;
		}

		std::string toString() override
		{
			std::string result = "<Factory{Builder}>";
			result += "<Cell>";
			result += this->cell->toString();
			result += "\n";
			return result;
		};

	};
		template<>
		class Factory<MilitaryUnit> : public GameObject
		{
		public:
			Cell* cell;
			Factory(Cell* cell) : cell(cell) { std::cout << "Factory<MilitaryUnit>::Factory()" << std::endl; };
			~Factory() { std::cout << "~Factory<MilitaryUnit>::Factory()" << std::endl; };
			MilitaryUnit* getUnit(const std::string& unitType, int health, int damage, bool defense, Cell* cell, Player* player)
			{
				MilitaryUnit* unit = nullptr;
				if (unitType == "infantry") { unit = new Infantry(health, damage, defense, cell, player); }
				if (unitType == "cavalry") { unit = new Cavalry(health, damage, defense, cell, player); }
				player->addGameObject(unit);
				return unit;
			}
			std::string toString() override
			{
				std::string result = "<Factory{MilitaryUnit}>";
				result += "<Cell>";
				result += this->cell->toString();
				result += "\n";
				return result;
			};

		};

		template<>
		class Factory<Medic> : public GameObject
		{
		public:
			Cell* cell;
			Factory(Cell* cell) : cell(cell) { std::cout << "Factory<MilitaryUnit>::Factory()" << std::endl; };
			~Factory() { std::cout << "~Factory<MilitaryUnit>::Factory()" << std::endl; };
			Medic* getUnit(const std::string& unitType, int health, int damage, bool defense, Cell* cell, Player* player)
			{
				Medic* unit = nullptr;
				if (unitType == "medic") { unit = new Medic(health, defense, cell, player); }
				player->addGameObject(unit);
				return unit;
			}
			std::string toString() override
			{
				std::string result = "<Factory{Medic}>";
				result += "<Cell>";
				result += this->cell->toString();
				result += "\n";
				return result;
			};

		};

