#ifndef DATA_H
# define DATA_H

// ESSENTIAL HEADERS
# include <iostream>
# include <fstream>
# include <string>
# include <vector>

// other HEADERS
# include "CONTAINER.h"

using namespace std;

//Write a new text file
void NEW_SAVE_FILE(const string& filename, const vector<int>& numbers) {
    ofstream file(filename);

    if (file.is_open()) {
        for (int number : numbers) {
            file << number << endl;
        }
        file.close();
        cout << "Successful!" << endl;
    } else {
        cerr << "Writing Error!" << endl;
    }
}

// Variables from Text file
vector<int> SAVE_DATA_FROM_FILE(const string& filename) {
    vector<int> numbers;
    ifstream file(filename);

    if (file.is_open()) {
        int number;
        while (file >> number) {
            numbers.push_back(number);
        }
        file.close();
    } else {
        cerr << "Open Error!" << endl;
    }

    return numbers;
}

// Read a text file
void READ_DATA_FROM_FILE(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Open Error!" << endl;
    }
}

#endif