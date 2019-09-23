#pragma once
#include "Unit.h"
#include "Cell.h"

class MilitaryUnit : public Unit
{
public:
	MilitaryUnit(int, int, bool, Cell*, Player*);
	~MilitaryUnit();
	void attack(Unit&);
	virtual std::string toString() override;
	static Unit::Bonus bonus;



protected:
	int getAttackBonus();
	Unit::Bonus getBonusMapping()=0;
	int damage;


private:

};

