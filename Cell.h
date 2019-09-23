#pragma once
#include "GameObject.h"
#include <string>

class Cell : public GameObject
{
public:
	enum Landscape
	{
		field,
		water,
		sand,
		forest,
		swamp,
		mount
	} landscape;

	Cell();
	Cell(Landscape);
	Cell(const Cell &);
	enum Landscape getLandscape();
	void setLandscape(Landscape);
	virtual ~Cell();
	virtual std::string toString() override;


};

