#include <string>
#include "FactoryUnit.hpp"
#include "Builder.h"

template<class T>
Factory<T>* getDepartment(const Builder* builder)
{
	Factory<T>* ptr = nullptr;
	ptr = builder->buildAFactory<T>();

	return ptr;
}