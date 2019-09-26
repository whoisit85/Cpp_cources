#pragma once
#include "GameObject.h"
#include <string>

class Cell : public GameObject
{
public:
	struct Point { unsigned int x; unsigned int y; } point;
	enum Landscape
	{
		field, // 0
		water,// 1
		sand,// 2
		forest,// 3
		swamp,// 4
		mount// 5
	} landscape;

	//Cell();
	Cell(Landscape, Point);
	Cell(const Cell &);
	enum Landscape getLandscape();
	void setLandscape(Landscape);
	virtual ~Cell();
	std::string landscapeToString(Cell::Landscape);
	virtual std::string toString() override;

};

