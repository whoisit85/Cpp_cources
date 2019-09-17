#pragma once
#include"MilitaryUnit.h"


class GroundTroops : public MilitaryUnit
{
public:
	GroundTroops(int, int, bool, Cell*, Player*);
	~GroundTroops();
	void attack(Unit&);
	static Unit::Bonus bonus;
	virtual std::string toString() override;


protected:
	int getAttackBonus();
	//Unit::Bonus getBonusMapping() = 0;



private:

};

