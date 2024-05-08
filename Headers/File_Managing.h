#ifndef File_Managing_h
# define File_Managing_h

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Example Functions :
// Write new 
void write_file(const string& filename, const string& content) {
    ofstream file(filename, ios::out); // out mode
    if (file.is_open()) {
        file << content; // write
        file.close(); // close
        cout << "File '" << filename << "' written successfully." << endl;
    } else {
        cerr << "Error opening file '" << filename << "'." << endl;
    }
}

// Append content on file 
void append_content(const string& filename, const string& content) {
    ofstream file(filename, ios::app); 
    if (file.is_open()) {
        file << content; // append
        file.close(); 
        cout << "Content appended to file '" << filename << "' successfully." << endl;
    } else {
        cerr << "Error opening file '" << filename << "'." << endl;
    }
}

// Read file
string read_file(const string& filename) {
    ifstream file(filename); // input
    string content, line;
    if (file.is_open()) {
        while (getline(file, line)) { // read line(s)
            content += line + "\n"; // assign
        }
        file.close(); 
    } else {
        cerr << "Error opening file '" << filename << "'." << endl;
    }
    return content;
}

#endif