#include "CreationtBuilder.h"
#include "Builder.h"


Builder* CreationBuilder::creationBuilder(int health, bool defense, Cell* cell, Player* player)
{
	Builder* builder = new Builder(health, defense, cell, player);

	player->addGameObject(builder);
	return builder;
}
