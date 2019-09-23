#include"Cell.h"
#include<string>

Cell::Cell() :landscape(field) {};
Cell::Cell( Cell::Landscape land) : landscape(land) {};


Cell::Landscape Cell::getLandscape()
{
	return this->landscape;
}
void Cell::setLandscape(Cell::Landscape land)
{
	this->landscape = land;
}
Cell::~Cell() {}

std::string Cell::toString()
{
	std::string result = "Cell: coorditates x,y";
	//TODO kuku 
	return result;
}
;
Cell::Cell(const Cell & cell): landscape(cell.landscape)
{

}


