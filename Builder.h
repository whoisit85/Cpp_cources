#pragma once
#include <string>
#include "FactoryUnit.hpp"
#include "FactoryGroundTroops.h"
#include "FactoryEngineeringTroops.h"
#include "FactoryMedic.h"
#include "CivilUnit.h"
#include "GroundTroops.h"
#include "Medic.h"
#include "Player.h"



class Builder :public CivilUnit
{
public:
	Builder(int, bool, Cell*, Player*);
	~Builder();

	template<class T>
	typename Factory<T>* buildAFactory() const;

	static Unit::Bonus bonus;
	virtual std::string toString() override;
protected:
	Unit::Bonus getBonusMapping();

private:
	//template<typename T>
	//void addDepartment(Factory<T>*);

private:
	//std::vector<Factory<T>*> departments;   ????????????????????????????????


};
