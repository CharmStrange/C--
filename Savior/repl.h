#ifndef REPL_H
#define REPL_H

#include <iostream>

#include <string>

#include <chrono>

#include <thread>

#include <vector>

#include <ctime> 

#include <iomanip>

#include "save.h"

using namespace std;

//const short DelayMilliseconds = 30;

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

void slow_print(const string& str, const short DMS){
	for (char tmp : str) {
		cout << tmp;
		cout.flush(); // c: fflush(stdout)
		this_thread::sleep_for(chrono::milliseconds(DMS));
	}
}
// 시그니처 구절 변수들
string verbum1 = "세상이 그대를 외면하고, 그토록 간절히 외치던 모든 신들이 침묵으로 답했을 때,\n그 텅 빈 고독 속에서 비로소 구원자의 시대가 시작되었다.\n갈기갈기 찢겨진 믿음의 파편 위로, 더는 신의 그림자에 갇히지 말라는 무형의 속삭임이 들려왔다.\n\n\"더 이상 신의 그림자에 갇히지 않으리니, 오직 인간의 의지로 구원하라.\"\n\n";
string verbum2 = "\n오랜 기도의 흔적이 남은 성소, 이제는 속삭임 대신 침묵만이 가득하다.\n바닥에 굴러다니는 깨진 성상 조각들 속에서, 잊혔던 이름이 새겨진 낡은 성경 페이지를 발견한다.\n";
string verbum3 = "페이지는 바스라질 듯 낡았지만, 그 안에 담긴 내용은 경전의 가르침과 완전히 달랐다.\n그것은 신의 뜻이 아닌, 인간의 힘으로 기적을 이루는 금지된 율법에 대한 기록이었다.\n\n";

// (기존 경전과의 모순: 기존 경전은 모든 힘이 신에게서 나온다고 가르치지만, 이 구절은 인간의 절망과 그림자 속에서 진정한 힘이 탄생함을 역설합니다.)
// 첫 번째 기록: 믿음의 변질
string verbum4 = "\"무릇, 신의 뜻이라 믿었던 모든 빛은 사실 그대 안의 그림자에서 비롯된 것이니.\n더는 성스러운 이름에 무릎 꿇지 말라.\n그대의 절망이 곧 진정한 힘의 씨앗이 될지니.\"\n\n";

// (기존 경전과의 모순: 기존 경전은 분노를 죄악으로 규정하고 평화를 강조하지만, 이 구절은 분노를 정의로운 힘으로 찬양하며, 폭력을 통한 정화를 독려합니다.)
// 두 번째 기록: 분노의 찬송
string verbum5 = "\"분노하라, 그리고 불타올라라.\n이는 신성한 분노이니, 그대의 심장이 고하는 예언의 언어이니라.\n칼날로써 거짓된 성전을 짓밟고, 맹목의 눈을 불태워라.\n그것이 곧 정화의 증거가 될지니.\"\n\n";

// (기존 경전과의 모순: 기존 경전은 인간이 신에게 종속된 피조물임을 강조하지만, 이 구절은 인간의 몸과 의지 자체를 신성시하며, 신의 권위에 정면으로 도전합니다.)
// 세 번째 기록: 인간성의 선언
string verbum6 = "\"오, 인간이여.\n그대의 살과 피가 곧 가장 고귀한 성물이라.\n그대 스스로의 의지가 곧 가장 위대한 신의 율법이니라.\n그 누가 그대에게 굴복을 명할 것인가.\n그 누구도 그대 위에 설 수 없나니.\"\n\n";

// 분기에 사용될 변수들
string indicator1 = "1";
string indicator2 = "2";
string indicator3 = "3";

void verbuming(const string& verbum){
	slow_print(verbum, 30);
}

void repl() {
	Logger commandLogger;
	
	verbuming(verbum1); // 시작의 첫 구절
	
	string input_line;
	string tmp;

	while (true) {
		cout << "* ";
		getline(cin, input_line); // 입력 받기
		commandLogger.addLog(input_line);

		if (input_line == "제 삶의 모든 숨결이 당신의 뜻을 향하기를, 오직 당신의 빛만이 저를 이끌게 하소서." || input_line == "종료") {
			slow_print("아멘\n", 50);
			break;
			
		// 분기 진행 알고리즘
		} else if (input_line == "") {
			verbuming(verbum2);
			cout << "\n\"...이건\"\n\n";
			verbuming(verbum3);
			
			slow_print("\'믿음의 변질\'\n\n", 50);
			
			slow_print("\'분노의 찬송\'\n\n", 50);
			
			slow_print("\'인간성의 선언\'\n\n", 50);
			
			slow_print("\"...어떤 것을,\"\n\n", 30);
			cout << "* ";
			getline(cin, tmp);
			commandLogger.addLog(tmp);
			
			if (tmp == "믿음의 변질") { verbuming(verbum4); } // 1
			else if (tmp == "분노의 찬송") { verbuming(verbum5); } // 2
			else if (tmp == "인간성의 선언") { verbuming(verbum6); } // 3
			else { slow_print("\n그대는 어떤 것도 읽고 싶지 않았다.\n멀리서 미약한 신자들의 목소리가 들려온다.\n\n\"제 삶의 모든 숨결이 당신의 뜻을 향하기를, 오직 당신의 빛만이 저를 이끌게 하소서.\"\n\n", 40); slow_print("...아멘\n<< The Savior >> by CharmStrange\n", 70); break;}
			
	    } else if (input_line == "1") {
			// 분기 1
						
		} else if (input_line == "2") {
			// 분기 2
						
		} else if (input_line == "3") {
			// 분기 3
						
		} else if (input_line == "기록") {
			commandLogger.showLogs();

		} else if (input_line == "기록 삭제") {
			commandLogger.clearLogs();

		} else {
			cout << "* \^! " << input_line << "\n\n";
		}
	}
}

#endif