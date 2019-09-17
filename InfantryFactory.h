#pragma once

#include "Factory.h"
#include "MilitaryUnit.h"
#include <string>

class InfantryFactory : public Factory
{
public:
	InfantryFactory();
	~InfantryFactory() override;
	Unit* getUnit(const std::string&,int ,int , bool, Cell *) override;
};