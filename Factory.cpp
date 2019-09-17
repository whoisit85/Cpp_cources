#include "Factory.h"
#include "Unit.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

template <typename T>
Factory<T>::Factory()
{
	std::cout << "Factory::Factory()" << std::endl;
}

template <typename T>
Factory<T>::~Factory()
{
	std::cout << "Factory::~Factory()" << std::endl;
	//std::for_each(departments.begin(), departments.end(), [](Factory * factory) { delete factory; });
}

template <typename T>
T* Factory<T>::getUnit(const std::string& unitType, int health, int damage, bool defense, Cell* cell)
{
	T* unit = getUnit(unitType, health, damage, defense, cell);

	//std::vector<Factory*>::iterator iter = departments.begin();
	//while (unit == nullptr && iter != departments.end())
	//{
	//	unit = (*iter)->getUnit(unitType,health,damage,defense, cell);
	//	++iter;
	//}
	return unit;
}

//template<>
//Builder* Factory<Builder>::getUnit(const std::string& unitType, int health, int damage, bool defense, Cell* cell)
//{
//	Builder* unit = getUnit(unitType, health, damage, defense, cell);
//	return unit;
//}
////template <typename T>
//void Factory::addDepartment(Factory* factory)
//{
//	departments.push_back(factory);
//	return;
//}



