#pragma once
#include "Animal.h"

class Person :public Animal
{
protected:
	Person();
public:
	Person(string name, short age);
public:
	string Greet();
};

