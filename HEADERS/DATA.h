#ifndef DATA_H
# define DATA_H

// ESSENTIAL HEADERS
# include <iostream>
# include <fstream>
# include <string>
# include <vector>

using namespace std;

// Structure to hold player data
struct PlayerData {
    string name;
    int level;
    int experience;

    // Constructor to initialize data with default values
    PlayerData() : name(""), level(1), experience(1) {}
};

//Write a new text file with player data initialized to default values
void NEW_SAVE_FILE(const string& filename, const string& playerName) {
    ofstream file(filename);

    if (file.is_open()) {
        PlayerData player;
        player.name = playerName; // Set player name from user input
        file << player.name << " " << player.level << " " << player.experience << endl;
        file.close();
    } else {
        cerr << "Writing Error!" << endl;
    }
}

// Variables from Text file
PlayerData SAVE_DATA_FROM_FILE(const string& filename) {
    PlayerData player;
    ifstream file(filename);

    if (file.is_open()) {
        file >> player.name >> player.level >> player.experience;
        file.close();
    } else {
        cerr << "Open Error!" << endl;
    }

    return player;
}

// N
void SAVE_FILE_PROCESS(const string& playerName) {
    string save_file = "CHARACTER.txt";
    NEW_SAVE_FILE(save_file, playerName);
    PlayerData player = SAVE_DATA_FROM_FILE(save_file);

    cout << "\nPlayer Name: " << player.name << endl;
    cout << "Player Level: " << player.level << endl;
    cout << "Player Experience: " << player.experience << endl;
}

// K : Read data from saved file or display an error message if the file doesn't exist
void KEEP_PLAYING_SAVE() {
    string save_file = "CHARACTER.txt";
    ifstream file(save_file);

    if (!file.is_open()) {
        cerr << "There's no file!" << endl;
        return;
    }

    PlayerData player;
    file >> player.name >> player.level >> player.experience;
    file.close();

    cout << "\nPlayer Name: " << player.name << endl;
    cout << "Player Level: " << player.level << endl;
    cout << "Player Experience: " << player.experience << endl;
}

// 
void START_GAME() {
    cout << "\nThe game started." << endl;
}


#endif
