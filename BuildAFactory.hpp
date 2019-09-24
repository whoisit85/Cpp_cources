#pragma once
#include "Builder.h"
#include "FactoryUnit.hpp"

template<typename T>
Factory<T>* Builder::buildAFactory() const
{
	Factory<T>* newfactory = new Factory<T>();
	//player->addGameObject(newfactory);
	return newfactory;
}