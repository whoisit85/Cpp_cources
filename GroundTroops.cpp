#include "GroundTroops.h"


GroundTroops::~GroundTroops()
{
}

void GroundTroops::attack(Unit&)
{
}

GroundTroops::GroundTroops(int unitHelth, int unitDamage, bool defense, Cell* cell, Player* player) : MilitaryUnit(unitHelth, unitDamage, defense, cell, player)
{

}

std::string GroundTroops::toString() { return ""; };