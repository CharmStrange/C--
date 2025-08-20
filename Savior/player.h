#ifndef PLAYER_H
#define PLAYER_H

#define FaithThreshold 0
#define rageThreshold 0

#include <iostream>

#include <string>

#include <vector>

#include "phnomena.h"

using namespace std;

class Player {
private:
	string name;
	unsigned short energy;
	short faith;
	unsigned short rage;
	unsigned short power;
	
public:
	Player(const string& name, unsigned short energy, short faith, unsigned short rage, unsigned short power) : name(name), energy(energy), faith(faith), rage(rage), power(power) {}
	
	void showStatus() const {
        cout << "\n--- Player Status ---\n";
        cout << "Name: " << name << "\n";
        cout << "Energy: " << energy << "\n";
        cout << "Faith: " << faith << "\n";
        cout << "Rage: " << rage << "\n";
        cout << "Power: " << power << "\n";
        cout << "---------------------\n\n";
	}
	
	unsigned short extract(const string& name, const string& type, unsigned short number) {
		
	}
	
	void encounter(Phenomenon* phenomenon) {
		
	}
	
};

#endif
