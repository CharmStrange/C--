#ifndef GAME_ALGORITHM_H
# define GAME_ALGORITHM_H

# include <iostream>
# include <string>
# include "JOBS.h"

using namespace std;

unsigned short region;
string chosen_region;

unsigned short job;
string chosen_job;

unsigned short ENTITY_region;

// BEGIN.h
void INITIALIZE_SET() {
    cout << "There are 3 regions, 'Industrial Zone', 'Desolate Area', 'Peaceful Village'." << endl;
    cout << "Choose what you want - " << endl;
    cout << "[1] : 'Industrial Zone' \n[2] : 'Desolate Area' \n[3] : 'Peaceful Village'\n :";
    cin >> region;

    if (region == 1) {
        chosen_region = "Industrial Zone";
        ENTITY_region = 1;

        for (const string& index : industrialZoneJobs) {
            cout << "\n" << index << endl;
        }
    }

    else if (region == 2) {
        chosen_region = "Desolate Area";
        ENTITY_region = 2;

        for (const string& index : desolateAreaJobs) {
            cout << "\n" << index << endl;
        }
    }

    else {
        chosen_region = "Peaceful Village";
        ENTITY_region = 3;

        for (const string& index : peacefulVillageJobs) {
            cout << "\n" << index << endl;
        }
    }

}

void SET_STATS() {

}

void compare_stats() {

}

// MAIN.h
void GAME_PROCESS() {

}

#endif