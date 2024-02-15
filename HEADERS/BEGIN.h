#ifndef BEGIN_H
# define BEGIN_H

// ESSENTIAL HEADERS
# include <iostream>

// other HEADERS
# include "CONTAINER.h"
# include "DATA.h"

using namespace std;

// main process
unsigned char start_value;

void START_SCREEN(); // Forward Declaration

void RUN_BEGIN() {
    cout << "Welcome, this is 'Game Title'. Try various functions of 'Game Title' and take what you want.\n" << endl;
    do { START_SCREEN(); } while (start_value == 1);
}

// process functions
void user_start(char alphabet); // Forward Declaration
void NEW_GAME(); // Forward Declaration
void KEPP_PLAYING(); // Forward Declaration
void CREDIT_SCREEN(); // Forward Declaration

void START_SCREEN() {
    char alphabet;

    cout << "[N] : New Game" << endl;
    cout << "[K] : Keep Playing" << endl;
    cout << "[C] : Credit" << endl;
    cout << "[X] : Exit" << endl;

    cin >> alphabet;
    user_start(alphabet);
}

void user_start(char alphabet) {
    start_value = 1; // Reset start_value to 1 for the next iteration
    switch (alphabet) {
        case 'N':
        //case 'n':
            cout << "Starting a New Game..." << endl;
            start_value = 0;
            NEW_GAME();
            break;
            
        case 'K':
        //case 'k':
            cout << "Keep Playing...\n" << endl;
            // Add the logic for continuing the game
            start_value = 0;
            break;
            
        case 'C':
        //case 'c':
            cout << "Credit...\n" << endl;
            CREDIT_SCREEN();
            break;
            
        case 'X':
        //case 'x':
            exit(0);
            
        default:
            cout << "Invalid choice. Please choose [N], [K], or [O].\n" << endl;
    }
}
///  
///
///
void NEW_GAME() {
    string new_save_name;
    cout << "Type player name : ";
    cin >> new_save_name;
    PLAYER_SAVE NEW_ONE(new_save_name);
    NEW_ONE.display_saves();

    SAVE_FILE_PROCESS(new_save_name);
}

void KEEP_PLAYING() {
    
}
/// 
///
///
void CREDIT_SCREEN() {
    cout << "Developer : CharmStrange / Intelligence Utility" << endl;
    cout << "Developing Language : C++" << endl;
    cout << "Developing Period : 2024-01-24 ~ " << endl;
    cout << "GitHub : https://github.com/CharmStrange" << endl;
    cout << "(return to start page...)\n" << endl;
}

#endif