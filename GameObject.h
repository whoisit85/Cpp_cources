#pragma once
#include <string>
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual std::string toString() = 0;
};

