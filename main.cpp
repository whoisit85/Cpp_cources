#include "FactoryUnit.hpp"
#include "Builder.h"
#include <string>
#include <iostream>
//#include "getDepartment.h"
#include "GroundTroops.h"
#include "Cell.h"
#include "BuildAFactory.hpp"
#include "Game.h"
#include "CreationtBuilder.h"
#include "asio.hpp"

int main(int argv, char* argc[])
  {
	Game game;
	Player player1;
	game.addPlayer(&player1);

	std::string unitType1 = "infantry";   //��������� �������� ��� �������
	Cell cell(Cell::field, { 1, 1 });
	Cell* ptrCell = &cell;

	std::string factoryType = "groundTroops";   
	std::string factoryType2 = "engineeringTroops";

	std::string unitType3 = "builder";

	CreationBuilder crB;
	//Builder* builder = crB.creationBuilder(100, false, ptrCell, &player1); //int health, bool defense, Cell* cell, Player* player
	//Builder* builder2 = crB.creationBuilder(100, false, ptrCell, &player1);

	Player player2;
	game.addPlayer(&player2);
	//Builder* builder3 = crB.creationBuilder(100, false, ptrCell, &player2); //int health, bool defense, Cell* cell, Player* player
	Builder* builder4 = crB.creationBuilder(100, false, ptrCell, &player2);
	Factory<MilitaryUnit>* fac = builder4->buildAFactory<MilitaryUnit>();
	//fac->getUnit(unitType1, 32, 88, true, ptrCell, &player2);
	fac->getUnit("tank", 33, 99, false, ptrCell, &player2);

	//Factory<Builder> * fac = builder->buildAFactory<Builder>();
	//builder->buildAFactory<Medic>();
	//fac->getUnit(unitType3, 32, 88, true, ptrCell, &player1);

	
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

	
	game.saveGametoFile();

	game.loadGame("game.txt");

	return 0;
}