#ifndef SAVE_H
#define SAVE_H

#include <iostream>

#include <fstream>

#include <string>

using namespace std;

// 저장할 변수들 : PLAYER_H
struct SaveData {
	string name;
	unsigned short energy;
	short faith;
	unsigned short rage;
	unsigned short power;
};

#endif
