#pragma once
#include <string>
#include "FactoryUnit.hpp"

class Medic;

template<>
class Factory<Medic>
{
public:
	Factory();
	~Factory();
	Medic* getUnit(const std::string&, int, int, bool, Cell*, Player *);
};