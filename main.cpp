#include "FactoryUnit.hpp"
#include "Builder.h"
#include <string>
#include <iostream>
//#include "getDepartment.h"
#include "GroundTroops.h"
#include "Cell.h"
#include "BuildAFactory.hpp"

int main(int argv, char* argc[])
{
	
	std::string unitType1 = "infantry";   //��������� �������� ��� �������
	Cell cell(Cell::field);
	Cell* ptrCell = &cell;

	std::string factoryType = "groundTroops";   
	std::string factoryType2 = "engineeringTroops";

	std::string unitType3 = "builder";
	Player player1;
	
	Builder* builder = new Builder(100, false, ptrCell, &player1);
	
	builder->buildAFactory<Builder>();
	builder->buildAFactory<Medic>();

	
	//factory1.addDepartment(getDepartment(factoryType, builder));
	//Factory<Builder>* factory=getDepartment<Builder>(builder);
	//factory->getUnit(unitType1, 100, 25, 0, ptrCell);

	//factory1.addDepartment(getDepartment(unitType1));
	//Builder* unit1 = factory->getUnit(unitType3, 100, 25, 0, ptrCell);
	//Factory<GroundTroops>* factory3 = unit1->buildAFactory<GroundTroops>();
	//Factory<Builder> factory2;
	//factory1.addDepartment(getDepartment(factoryType2, builder));
	//Builder* unitBuilder = factory2.getUnit(unitType3, 100, 0, 0, ptrCell);
	//Builder* b = &unitBuilder;
	//std::string unitType4 = "medic";
	//Factory<Medic>* factory4 = getDepartment<Medic>(builder);
	//Medic* unitM = factory4->getUnit(unitType4, 100, 0, 0, ptrCell);
	

	//std::string unitType2 = "cavalry";   //��������� �������� ��� �������
	////Factory factory2;
	//factory1.addDepartment(getDepartment(factoryType, unitBuilder));
	//Unit* unit2 = factory1.getUnit(unitType2, 150, 40,1, ptrCell);


	//unit1->printUnit();
//	unit2->printUnit();

	//unit2->attack(*unit1);////////////////////////////////////////////////
	//unit1->printUnit();
	//unit2->printUnit();
	// use unit there
	//delete unit1;
	//delete unit2;
	return 0;
}