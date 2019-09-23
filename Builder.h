#pragma once
#include <string>
#include "CivilUnit.h"
#include "GroundTroops.h"
#include "Medic.h"
#include "Player.h"

template<typename T>
class Factory;



class Builder :public CivilUnit
{
public:
	Builder(int, bool, Cell*, Player*);
	~Builder();


	template<typename T>
	Factory<T>* buildAFactory() const;

	//void  buildAFactory() const;

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
