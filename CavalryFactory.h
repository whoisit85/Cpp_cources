#pragma once

#include "Factory.h"
#include "Unit.h"
#include <string>

class CavalryFactory : public Factory
{
public:
	CavalryFactory();
	~CavalryFactory()override;
	Unit* getUnit(const std::string&,int ,int, bool, Cell *) override;
};