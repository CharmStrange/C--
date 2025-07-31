#ifndef REPL_H
#define REPL_H

#include <iostream>

#include <string>

#include <chrono>

#include <thread>

#include <vector>

#include <ctime> 

#include <iomanip>

using namespace std;

const short DelayMilliseconds = 30;

class Logger {
private:
	vector<string> logs;
	
public:
	Logger() {}
	void addLog(const string& entry) {
		// Timestamp
		auto now = chrono::system_clock::now();
		time_t now_c = chrono::system_clock::to_time_t(now);
		stringstream ss;
		ss << "[" << put_time(localtime(&now_c), "%Y-%m-%d %H:%M:%S") << "] " << entry;
		logs.push_back(ss.str());
		//logs.push_back(entry); // Simpler logging without timestamp for now
	}
	
    // Method to display all logs
    void showLogs() const {
        if (logs.empty()) {
            cout << "No commands logged yet.\n";
            return;
        }
        cout << "--- Command Log ---\n";
        for (size_t i = 0; i < logs.size(); ++i) {
            cout << "[" << i + 1 << "] " << logs[i] << "\n";
        }
        cout << "-------------------\n";
    }

    // Method to clear all logs (optional)
    void clearLogs() {
        logs.clear();
        cout << "Command log cleared.\n";
    }
};

void slow_print(const string& str){
	for (char tmp : str) {
		cout << tmp;
		cout.flush(); // c: fflush(stdout)
		this_thread::sleep_for(chrono::milliseconds(DelayMilliseconds));
	}
}

string verbum = "";
void repl() {
	Logger commandLogger;

	slow_print("세상이 그대를 외면했을 때, 모든 신이 침묵했을 때, 비로소 구원자의 시대가 시작되리라.\n");

	string input_line;

	while (true) {
		cout << "* ";
		getline(cin, input_line); // 입력 받기
		commandLogger.addLog(input_line);

		if (input_line == "제 삶의 모든 숨결이 당신의 뜻을 향하기를, 오직 당신의 빛만이 저를 이끌게 하소서.") {
			slow_print("아멘\n");
			break;

		} else if (input_line == "기록") {
			commandLogger.showLogs();

		} else if (input_line == "기록 삭제") {
			commandLogger.clearLogs();

		} else {
			cout << "* !" << input_line << "\n\n";
		}
	}
}

#endif
