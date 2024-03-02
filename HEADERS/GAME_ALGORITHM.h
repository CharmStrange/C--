#ifndef GAME_ALGORITHM_H
# define GAME_ALGORITHM_H

# include <iostream>
# include <string>
# include <random>
# include <ctime>

# include "MAIN.h"
# include "JOBS.h"

using namespace std;

unsigned char region;
string chosen_region;

unsigned char job;
string chosen_job;

unsigned char ENTITY_region;

string Randomizer(const vector<string>& string_container) {
    mt19937 rng(time(nullptr));
    uniform_int_distribution<int> dist(0, string_container.size() - 1);

    unsigned char Random_Index = dist(rng);
    return string_container[Random_Index];
}

class STAT {
public:
    unsigned char A;
    unsigned char B;
    unsigned char C;
    unsigned char D;
    unsigned char E;

};

// F.D.
void spawn_NPC();
void spawn_ENTITY();

// BEGIN.h
void INITIALIZE_SET() {
    cout << "\nThere are 3 regions, 'Industrial Zone', 'Desolate Area', 'Peaceful Village'." << endl;
    cout << "Choose what you want - " << endl;
    cout << "[1] : 'Industrial Zone' \n[2] : 'Desolate Area' \n[3] : 'Peaceful Village'\n :";
    cin >> region;

    if (region == 1) {
        chosen_region = "Industrial Zone";
        ENTITY_region = 1;

        for (const string& index : industrialZoneJobs) {
            cout << "\n" << index << endl;
        }
        cout << endl;

        spawn_NPC();
        spawn_ENTITY();
    }

    else if (region == 2) {
        chosen_region = "Desolate Area";
        ENTITY_region = 2;

        for (const string& index : desolateAreaJobs) {
            cout << "\n" << index << endl;
        }
        cout << endl;

        spawn_NPC();
        spawn_ENTITY();
    }

    else {
        chosen_region = "Peaceful Village";
        ENTITY_region = 3;

        for (const string& index : peacefulVillageJobs) {
            cout << "\n" << index << endl;
        }
        cout << endl;

        spawn_NPC();
        spawn_ENTITY();
    }

}

void SET_STATS() {
    if (chosen_region == "Industrial Zone") { // 1
        
    }

    else if (chosen_region == "Desolate Area") { //2
        
    }

    else { //3 

    }
}

void spawn_NPC() {
    if (ENTITY_region == 1) {
        cout << "\nSpawned random NPC : ";
        cout << Randomizer(industrialZoneNPCs) << endl;
    }

    else if (ENTITY_region == 2) {
        cout << "\nSpawned random NPC : ";
        cout << Randomizer(desolateAreaNPCs) << endl;
    }

    else {
        cout << "\nSpawned random NPC : ";
        cout << Randomizer(peacefulVillageNPCs) << endl;
    }
}

void spawn_ENTITY() {
    if (ENTITY_region == 1) {
        cout << "\nSpawned random ENTITY : ";
        cout << Randomizer(industrialZoneEntities) << endl;
    }

    else if (ENTITY_region == 2) {
        cout << "\nSpawned random ENTITY : ";
        cout << Randomizer(desolateAreaEntities) << endl;
    }

    else {
        cout << "\nSpawned random ENTITY : ";
        cout << Randomizer(peacefulVillageEntities) << endl;
    }
}

void compare_stats() {
    cout << endl;
}

// MAIN.h
void GAME_PROCESS() {

}

#endif