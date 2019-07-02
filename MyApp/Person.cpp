#include "Person.h"

Person::Person()
{

}
Person::Person(string name, short age) :Animal(name, age)
{
	int a = 1;
}

string Person::Greet()
{
	//return	Animal::Greet();
	return "我是子类的哦";
}


