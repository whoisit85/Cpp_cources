#pragma once
#include <string>
#include "Cell.h"
#include <map>
#include "GameObject.h"

class Player;

class Unit : public GameObject
{
public:
	void setHealth(int);
	Unit(int , bool, Cell *, Player * );
	Unit(const Unit&);
	virtual ~Unit();

	int getHealth();
	virtual void move(const int&, const int&);

	struct Bonus
	{
		const std::map <Cell::Landscape, int> attackBonus;
		const std::map < Cell::Landscape, int > defenseBonus;
	};

	virtual void printUnit()const;
	//virtual std::string whoAmI();
	Cell * cell;
	 
	virtual bool getDefense()const;
	virtual std::string toString() override;
	int getDefenseBonus();

protected: 
	Player* player;
	virtual Bonus getBonusMapping() = 0;
private:
	int health;
	bool defense;
	
};  