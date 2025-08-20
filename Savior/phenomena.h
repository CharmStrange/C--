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
	
public:
	Phenomenon(const string& name, const string& type, unsigned short number);
};

#endif
