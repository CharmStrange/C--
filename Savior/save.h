#ifndef SAVE_H
#define SAVE_H

#include <iostream>

#include <fstream>

#include <string>

#include <tinyxml2.h>  // tinyxml2 라이브러리 추가

using namespace std;
using namespace tinyxml2;

// 저장할 변수들 : PLAYER_H
struct SaveData {
	string name;
	unsigned short energy;
	short faith;
	unsigned short rage;
	unsigned short power;
};

// 데이터를 XML 로 
void Save(const SaveData& data) {
    XMLDocument doc;

    // 세이브 파일이 없으면 새로 생성
    ifstream ifile("save.xml");
    if (!ifile) {
        // 새로 생성하는 부분
        XMLElement* root = doc.NewElement("GameSave");
        doc.InsertFirstChild(root);

        // 데이터 저장
        XMLElement* nameElement = doc.NewElement("Name");
        nameElement->SetText(data.name.c_str());
        root->InsertEndChild(nameElement);

        XMLElement* energyElement = doc.NewElement("Energy");
        energyElement->SetText(data.energy);
        root->InsertEndChild(energyElement);

        XMLElement* faithElement = doc.NewElement("Faith");
        faithElement->SetText(data.faith);
        root->InsertEndChild(faithElement);

        XMLElement* rageElement = doc.NewElement("Rage");
        rageElement->SetText(data.rage);
        root->InsertEndChild(rageElement);

        XMLElement* powerElement = doc.NewElement("Power");
        powerElement->SetText(data.power);
        root->InsertEndChild(powerElement);

        // 파일로 저장
        doc.SaveFile("save.xml");
        cout << "새 파일 생성 완료." << endl;
        // 종료 알고리즘 추가해야 함
    }
    else {
        // 이미 존재하는 세이브 파일을 읽어오기
        doc.LoadFile("save.xml");

        XMLElement* root = doc.FirstChildElement("GameSave");
        if (root) {
            XMLElement* nameElement = root->FirstChildElement("Name");
            XMLElement* energyElement = root->FirstChildElement("Energy");
            XMLElement* faithElement = root->FirstChildElement("Faith");
            XMLElement* rageElement = root->FirstChildElement("Rage");
            XMLElement* powerElement = root->FirstChildElement("Power");

            if (nameElement && energyElement && faithElement && rageElement && powerElement) {
                string name = nameElement->GetText();
                unsigned short energy = energyElement->UnsignedText();
                short faith = faithElement->IntText();
                unsigned short rage = rageElement->UnsignedText();
                unsigned short power = powerElement->UnsignedText();

                cout << "세이브 데이터 읽기: " << endl;
                cout << "이름: " << name << endl;
                cout << "에너지: " << energy << endl;
                cout << "신앙도: " << faith << endl;
                cout << "분노: " << rage << endl;
                cout << "힘: " << power << endl;
            }
        }
    }
}

#endif
