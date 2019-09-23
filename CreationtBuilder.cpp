#include "CreationtBuilder.h"
#include "Builder.h"


Builder* CreationBuilder::creationBuilder(int health, bool defense, Cell* cell, Player* player)
{
	return new Builder(health, defense, cell, player);
}
