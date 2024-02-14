#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// 텍스트 파일을 작성하는 함수
void writeNumbersToFile(const std::string& filename, const std::vector<int>& numbers) {
    std::ofstream file(filename);

    if (file.is_open()) {
        for (int number : numbers) {
            file << number << std::endl;
        }
        file.close();
        std::cout << "숫자가 파일에 성공적으로 작성되었습니다." << std::endl;
    } else {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
    }
}

// 텍스트 파일에서 숫자들을 읽어 변수에 저장하는 함수
std::vector<int> readNumbersFromFile(const std::string& filename) {
    std::vector<int> numbers;
    std::ifstream file(filename);

    if (file.is_open()) {
        int number;
        while (file >> number) {
            numbers.push_back(number);
        }
        file.close();
    } else {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
    }

    return numbers;
}

// 텍스트 파일의 내용을 전부 출력하는 함수
void printFileContents(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
    }
}

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50};
    std::string filename = "numbers.txt";

    // 숫자가 적힌 텍스트 파일 작성
    writeNumbersToFile(filename, numbers);

    // 텍스트 파일에서 숫자들 읽기
    std::vector<int> readNumbers = readNumbersFromFile(filename);
    std::cout << "파일에서 읽은 숫자들:" << std::endl;
    for (int number : readNumbers) {
        std::cout << number << std::endl;
    }

    // 텍스트 파일 내용 출력
    std::cout << "텍스트 파일 내용:" << std::endl;
    printFileContents(filename);

    return 0;
}