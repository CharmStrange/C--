#ifndef SAVE_H
#define SAVE_H

#include <iostream>

#include <fstream>

#include <string>

#include <tinyxml2.h>  // tinyxml2 라이브러리 추가

using namespace std;
using namespace tinyxml2;

// 저장할 변수들 (예시)
struct SaveData {
	string name;
	unsigned short energy;
	short faith;
	unsigned short rage;
	unsigned short power;
};

// 세이브 데이터를 XML로 저장하는 함수
void Save(const SaveData& data) {
    XMLDocument doc;

    // 세이브 파일이 없으면 새로 생성
    ifstream ifile("save.xml");
    if (!ifile) {
        // 새로 생성하는 부분
        XMLElement* root = doc.NewElement("GameSave");
        doc.InsertFirstChild(root);

        // 데이터 저장
        XMLElement* levelElement = doc.NewElement("Level");
        levelElement->SetText(data.level);
        root->InsertEndChild(levelElement);

        XMLElement* nameElement = doc.NewElement("Name");
        nameElement->SetText(data.name.c_str());
        root->InsertEndChild(nameElement);

        XMLElement* healthElement = doc.NewElement("Health");
        healthElement->SetText(data.health);
        root->InsertEndChild(healthElement);

        // 파일로 저장
        doc.SaveFile("save.xml");
        cout << "새 세이브 파일이 생성되었습니다!" << endl;
    }
    else {
        // 이미 존재하는 세이브 파일을 읽어오기
        doc.LoadFile("save.xml");

        XMLElement* root = doc.FirstChildElement("GameSave");
        if (root) {
            XMLElement* levelElement = root->FirstChildElement("Level");
            XMLElement* nameElement = root->FirstChildElement("Name");
            XMLElement* healthElement = root->FirstChildElement("Health");

            if (levelElement && nameElement && healthElement) {
                int level = levelElement->IntText();
                string name = nameElement->GetText();
                float health = healthElement->FloatText();

                cout << "세이브 데이터 읽기: " << endl;
                cout << "Level: " << level << endl;
                cout << "Name: " << name << endl;
                cout << "Health: " << health << endl;
            }
        }
    }
}

#endif
