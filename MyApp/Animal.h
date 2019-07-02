#pragma once
#include <string>
using namespace std;

class Animal {
public:
	string Name;
	short Age;
	static short Flag;
protected:
	Animal();
public:
	Animal(string name, short age);
public:
	virtual	string Greet();
	static Animal* GetInstance();
};