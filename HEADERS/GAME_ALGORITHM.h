#ifndef GAME_ALGORITHM_H
# define GAME_ALGORITHM_H

# include <iostream>
# include <string>
# include "JOBS.h"

using namespace std;

// BEGIN.h
void CHOOOSE_JOB() {
    unsigned short A;
    cout << "There are 3 regions, 'Industrial Zone', 'Desolate Area', 'Peaceful Village'." << endl;
    cout << "Choose what you want - " << endl;
    cout << "[1] : 'Industrial Zone' \n[2] : 'Desolate Area' \n[3] : 'Peaceful Village'\n :";
    cin >> A;

    if (A == 1) {
        for (const string& index : industrialZoneJobs) {
            cout << "\n" << index << endl;
        }
    }

    else if (A == 2) {
        for (const string& index : desolateAreaJobs) {
            cout << "\n" << index << endl;
        }
    }

    else {
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