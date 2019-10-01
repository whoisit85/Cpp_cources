#include"Cell.h"
#include<string>
#include <iostream>

Cell::Cell(Landscape land, Point point) : landscape(land), point(point){};


Cell::Landscape Cell::getLandscape()
{
	return this->landscape;
}
void Cell::setLandscape(Cell::Landscape land)
{
	this->landscape = land;
}
Cell::~Cell() {}


std::string Cell::landscapeToString(Cell::Landscape land) 
{

	std::string result = "";
	switch (land)
	{
	case 0:
	{
		result = "field";
		break;
	}
	case 1:
	{
		result = "water";
		break;
	}
	case 2:
	{
		result = "sand";
		break;
	}
	case 3:
	{
		result = "forest";
		break;
	}
	case 4:
	{
		result = "swamp";
		break;
	}
	case 5:
	{
		result = "mount";
		break;
	}
	};
	return result;
}

//Cell::Landscape Cell::stringToLandscape(std::string)
//{
//	return Cell::Landscape();
//}

std::string Cell::toString()
{
	std::string result = "Landscape,";
	result += landscapeToString(this->getLandscape());
	result += ",";
	result += "point,";
	result += std::to_string(point.x);
	result += ",";
	result += std::to_string(point.y);
	return result;
}
;
Cell::Cell(const Cell & cell): landscape(cell.landscape), point(cell.point)
{

}


