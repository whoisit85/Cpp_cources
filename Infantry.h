#pragma once

#include "GroundTroops.h"
#include"Cell.h"

class Infantry : public GroundTroops
{
public:
	static Unit::Bonus bonus;
	virtual std::string toString() override;
	Infantry();
	Infantry(GroundTroops&);
	Infantry(int, int,bool, Cell *, Player*);
	~Infantry();

	void move(const int&, const int&) override;

protected:
	Unit::Bonus getBonusMapping() override;


private:


};