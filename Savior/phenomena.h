#ifndef PHENOMENA_H
#define PHENOMENA_H

#include <iostream>

#include <string>

#include <vector>

using namespace std;

class Phenomenon {
private:
	string name;
	string type;
	unsigned short number;
	unsigned short energy;
	short faith;
	unsigned short rage;
	unsigned short power;
	
public:
	Phenomenon(const string& name, const string& type, unsigned short number, unsigned short energy, short faith, unsigned short rage, unsigned short power) : name(name), type(type), number(number), energy(energy), faith(faith), rage(rage), power(power) {}
};

#endif
