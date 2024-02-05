#ifndef BEGIN_H
# define BEGIN_H

// ESSENTIAL HEADERS
# include <iostream>

// other HEADERS
# include "CONTAINER.h"

using namespace std;

// main process
void START_SCREEN();
void RUN_BEGIN() {
    START_SCREEN();
}

// process functions
void user_start(char alphabet);
void START_SCREEN() {
    char alphabet;

    cout << "Welcome, this is 'Game Title'. Try various functions of 'Game Title' and take what you want.\n" << endl;
    cout << "[N] : New Game" << endl;
    cout << "[K] : Keep Playing" << endl;
    cout << "[C] : Credit" << endl;

    cin >> alphabet;
    user_start(alphabet);
}

void user_start(char alphabet) {
    switch (alphabet) {
        case 'N':
        //case 'n':

            cout << "Starting a New Game..." << endl;
            // Add the logic for starting a new game
            break;
        case 'K':
        //case 'k':

            cout << "Keep Playing..." << endl;
            // Add the logic for continuing the game
            break;
        case 'O':
        //case 'o':

            cout << "Credit..." << endl;
            // Add the logic for displaying and handling options
            break;
        default:
            cout << "Invalid choice. Please choose [N], [K], or [O]." << endl;
    }
}

void CREDIT_SCREEN() {

}

#endif