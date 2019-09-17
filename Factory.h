#pragma once
#include "Unit.h"
#include <string>
#include <vector>
#include"Builder.h"

template <typename T>
class Factory
{
public:
	Factory();
	~Factory();
	T* getUnit(const std::string&,int ,int, bool, Cell *);

	//void addDepartment(Factory*);
private:
	//Factory<GroundTroops>* buildAFactory() const;
};

