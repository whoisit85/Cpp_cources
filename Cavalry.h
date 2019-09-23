#pragma once

#include "GroundTroops.h"

class Cavalry : public GroundTroops
{
public:
	static Unit::Bonus bonus;
	virtual std::string toString() override;

protected:
	Unit::Bonus getBonusMapping() override;

public:
	Cavalry();
	Cavalry(int, int,bool, Cell*, Player*);
	Cavalry(GroundTroops&);

	~Cavalry();

	void move(const int&, const int&);
	//int getAttackBonus()override;
	//int getDefenseBonus()override;

//	std::string whoAmI()override;



	//int forwardCoordinates;
	//int upCoordinates;

};