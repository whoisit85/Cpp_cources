#pragma once
#include"FactoryUnit.hpp"
#include"MilitaryUnit.h"
#include<string>
#include "Tank.h"


class TankFactory:public Factory<MilitaryUnit>
{
public:
	TankFactory();
	~TankFactory();

	MilitaryUnit* getUnit(const std::string&, int,int, bool,Cell*);

};

