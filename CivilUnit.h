#pragma once
#include "Unit.h"
#include "Cell.h"

//class Player;
//class Unit;

class CivilUnit : public Unit
{
public:
	CivilUnit(int, bool, Cell*, Player *);
	~CivilUnit();
	virtual std::string toString() override;

	Bonus getBonusMapping() = 0;

private:

};

