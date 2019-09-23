#pragma once
#include"CivilUnit.h"

class Medic : public CivilUnit
{
public:
	Medic(int, bool, Cell*, Player*);
	~Medic();
	//void treatment(Unit*);

	static Unit::Bonus bonus;
	virtual std::string toString() override;

protected:
	Unit::Bonus getBonusMapping();

private:

};

