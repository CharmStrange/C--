#include <iostream>
#include <fstream>
#include <string>

#include "Headers/File_Managing.h"
#include "Headers/Simulations.h"

using namespace std;

int main() {
    string filename = "example.txt";

    string contentToWrite = "Hello, World!\n";

    string contentToAppend = "This is additional content.\n";

    write_file(filename, contentToWrite);

    append_content(filename, contentToAppend);

    string fileContent = read_file(filename);
    cout << "File content:\n" << fileContent;

    return 0;
}
