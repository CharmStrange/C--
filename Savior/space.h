#ifndef SPACE_H
#define SPACE_H

#include <iostream>

#include <string>

#include <vector>

#include "player.h"

#include "phenomena.h"

using namespace std;

class Space {
private:
    string name;
    string description;
	
public:
	vector<Phenomenon*> phenomena_space;
	
    Space(const string& name, const string& description) {
		cout << description << endl;
	}
    
    void displayDescription() const;
	
    void encounter(Player& player, Phenomenon& phenomenon);

};

#endif
