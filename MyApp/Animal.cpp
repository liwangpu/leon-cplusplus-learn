#include <string>
#include <iostream>
#include <sstream>
#include "Animal.h"
using namespace std;

Animal::Animal()
{
}

Animal::Animal(string name, short age)
{
	Name = name;
	Age = age;
}

string Animal::Greet()
{
	std::ostringstream ostr;

	ostr << "I'm " << Name << "," << "my age is " << Age << "!" << endl;

	return ostr.str();
}

Animal* Animal::GetInstance()
{
	return  new Animal("Jim", 12);
}


short Animal::Flag = 12;