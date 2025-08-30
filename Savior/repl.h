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

#include "space.h"

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
    string input_line;

    slow_print(verbum1, 30); // 게임 시작 대사

    while (true) {
        cout << "* ";
        getline(cin, input_line);
        commandLogger.addLog(input_line);

        if (input_line.empty()) {
            slow_print(verbum2, 30);
            cout << "\n\"...이건\"\n\n";
            slow_print(verbum3, 30);

            slow_print("\'믿음의 변질\'\n\n", 50);
            slow_print("\'분노의 찬송\'\n\n", 50);
            slow_print("\'인간성의 선언\'\n\n", 50);

            cout << "* 어떤 것을 읽겠는가?\n";
            cout << "* ";

            string tmp;
            getline(cin, tmp);
            commandLogger.addLog(tmp);
            
            if (tmp == "믿음의 변질") { // 회의의 성소 
                slow_print(verbum4, 30);
                // 믿음의 변질 분기 스토리를 여기에 추가
				Space Sanctuary_of_Doubt("회의의 성소", "한때 순례자들이 모여들었던 '빛의 성소'.\n그러나 지금은 벽면을 따라 알 수 없는 언어의 낙서가 가득하고, 천장에서는 불경한 소리가 울려 퍼진다.\n성소의 신성한 힘은 사라지고, '거짓된 예언' 현상이 성소 전체를 뒤덮고 있다.\n");
				
				Phenomenon phenomenon1_space1("진실의 그림자", "Spectral", 1, 10, 20, 5, 10); 
				Sanctuary_of_Doubt.phenomena_space.push_back(&phenomenon1_space1);
				
        		Phenomenon phenomenon2_space1("속삭이는 성가대", "Illusion", 2, 5, 30, 0, 15); 
				Sanctuary_of_Doubt.phenomena_space.push_back(&phenomenon2_space1);
				
        		Phenomenon phenomenon3_space1("뒤틀린 묵상자", "Illusion", 3, 25, 15, 10, 20);
				Sanctuary_of_Doubt.phenomena_space.push_back(&phenomenon3_space1);
				
        		Phenomenon phenomenon4_space1("기만의 사제", "Spectral", 4, 15, 10, 5, 25);
				Sanctuary_of_Doubt.phenomena_space.push_back(&phenomenon4_space1);
				
        		Phenomenon phenomenon5_space1("고백의 거울", "Illusion", 5, 5, -10, 15, 10);
				Sanctuary_of_Doubt.phenomena_space.push_back(&phenomenon5_space1);
				
        		Phenomenon phenomenon6_space1("성물의 파수꾼", "Guardian", 6, 40, 30, 10, 30);
				Sanctuary_of_Doubt.phenomena_space.push_back(&phenomenon6_space1);
				
        		Phenomenon phenomenon7_space1("회개의 눈물", "Illusion", 7, 5, 25, 5, 10);
				Sanctuary_of_Doubt.phenomena_space.push_back(&phenomenon7_space1);
				
        		Phenomenon phenomenon8_space1("성스러운 거짓기말", "Illusion", 8, 1, 10, 0, 5);
				Sanctuary_of_Doubt.phenomena_space.push_back(&phenomenon8_space1);
				
        		Phenomenon phenomenon9_space1("불신의 사도", "Spectral", 9, 30, -20, 20, 35);
				Sanctuary_of_Doubt.phenomena_space.push_back(&phenomenon9_space1);
								
            } else if (tmp == "분노의 찬송") { // 증오의 지하 성당 
                slow_print(verbum5, 30);
                // 분노의 찬송 분기 스토리를 여기에 추가
				Space Chantry_of_Hatred("증오의 지하 성당", "겉보기에는 평범한 성당이지만, 지하로 내려가면 무고한 희생자들이 갇혀있던 감옥과 탐욕의 흔적들이 남아있다.");
				
				Phenomenon phenomenon1_space2("타락한 기사", "Corrupted", 10, 50, -10, 30, 40);
				Chantry_of_Hatred.phenomena_space.push_back(&phenomenon1_space2);
				
        		Phenomenon phenomenon2_space2("탐욕의 수호자", "Beast", 11, 45, -20, 40, 50);
				Chantry_of_Hatred.phenomena_space.push_back(&phenomenon2_space2);
				
        		Phenomenon phenomenon3_space2("쇠사슬 속박자", "Corrupted", 12, 35, -5, 25, 30);
				Chantry_of_Hatred.phenomena_space.push_back(&phenomenon3_space2);
				
        		Phenomenon phenomenon4_space2("부패한 사제", "Corrupted", 13, 30, -15, 30, 45);
				Chantry_of_Hatred.phenomena_space.push_back(&phenomenon4_space2);
				
        		Phenomenon phenomenon5_space2("피의 맹신자", "Corrupted", 14, 20, 10, 50, 40);
				Chantry_of_Hatred.phenomena_space.push_back(&phenomenon5_space2);
				
        		Phenomenon phenomenon6_space2("분노의 망령", "Spirit", 15, 25, -20, 60, 55);
				Chantry_of_Hatred.phenomena_space.push_back(&phenomenon6_space2);
				
        		Phenomenon phenomenon7_space2("배신의 짐승", "Beast", 16, 60, -30, 50, 60);
				Chantry_of_Hatred.phenomena_space.push_back(&phenomenon7_space2);
				
        		Phenomenon phenomenon8_space2("이단자의 심장", "Beast", 17, 70, -40, 50, 70);
				Chantry_of_Hatred.phenomena_space.push_back(&phenomenon8_space2);
				
        		Phenomenon phenomenon9_space2("공허한 복수자", "Spirit", 18, 55, -35, 70, 65);
				Chantry_of_Hatred.phenomena_space.push_back(&phenomenon9_space2);
								
            } else if (tmp == "인간성의 선언") { // 재림의 첨탑
                slow_print(verbum6, 30);
                // 인간성의 선언 분기 스토리를 여기에 추가
				Space Spire_of_Rebirth("재림의 첨탑", "구름을 뚫고 솟아 있는 거대한 첨탑.\n첨탑의 꼭대기에는 '신성한 힘'이 봉인되어 있던 제단이 있다.");
				
				Phenomenon phenomenon1_space3("신의 파편", "Celestial", 19, 80, 80, 0, 75);
				Spire_of_Rebirth.phenomena_space.push_back(&phenomenon1_space3);
				
        		Phenomenon phenomenon2_space3("공허한 천사", "Celestial", 20, 70, 60, 10, 80);
				Spire_of_Rebirth.phenomena_space.push_back(&phenomenon2_space3);
				
        		Phenomenon phenomenon3_space3("옛 성자의 망령", "Manifestation", 21, 90, 50, 50, 90);
				Spire_of_Rebirth.phenomena_space.push_back(&phenomenon3_space3);
				
        		Phenomenon phenomenon4_space3("운명의 매듭", "Abomination", 22, 50, 0, 70, 70);
				Spire_of_Rebirth.phenomena_space.push_back(&phenomenon4_space3);
				
        		Phenomenon phenomenon5_space3("아포스타시의 거상", "Abomination", 23, 120, -10, 80, 100);
				Spire_of_Rebirth.phenomena_space.push_back(&phenomenon5_space3);
				
        		Phenomenon phenomenon6_space3("마지막 기도", "Celestial", 24, 60, 90, 0, 85);
				Spire_of_Rebirth.phenomena_space.push_back(&phenomenon6_space3);
				
        		Phenomenon phenomenon7_space3("성장의 허상", "Manifestation", 25, 40, 40, 40, 70);
				Spire_of_Rebirth.phenomena_space.push_back(&phenomenon7_space3);
				
        		Phenomenon phenomenon8_space3("새로운 율법의 거울", "Manifestation", 26, 85, 0, 90, 95);
				Spire_of_Rebirth.phenomena_space.push_back(&phenomenon8_space3);
				
        		Phenomenon phenomenon9_space3("천상의 종말", "Abomination", 27, 200, 100, 100, 150);
				Spire_of_Rebirth.phenomena_space.push_back(&phenomenon9_space3);
								
            } else {
                slow_print("\n그대는 어떤 것도 읽고 싶지 않았다.\n", 40);
            }
        
        } else if (input_line == "종료" || input_line == "제 삶의 모든 숨결이 당신의 뜻을 향하기를, 오직 당신의 빛만이 저를 이끌게 하소서.") {
            slow_print("...아멘\n", 50);
            slow_print("<< The Savior >> by CharmStrange\n", 70);
            break;
        
        } else if (input_line == "기록") {
            commandLogger.showLogs();

        } else if (input_line == "기록 삭제") {
            commandLogger.clearLogs();

        } else {
            cout << "* ^! " << input_line << "\n\n";
        }
    }
}

#endif
