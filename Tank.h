#pragma once

#include "GroundTroops.h"

class Tank : public GroundTroops
{
public:
	static Unit::Bonus bonus;
	virtual std::string toString() override;

protected:
	Unit::Bonus getBonusMapping() override;

public:
	Tank();
	Tank(int, int, bool, Cell *, Player*);
	~Tank();


	void move(const int&, const int&);
	//int getAttackBonus()override;
	//int getDefenseBonus()override;


private:
	//int forwardCoordinates;
	//int upCoordinates;
};