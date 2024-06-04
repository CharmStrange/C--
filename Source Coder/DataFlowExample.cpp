#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

using namespace std;

// 데이터 구조체 정의
struct Data {
    string header_info;
    string actual_data;
    string dummy_data; // 필요에 따라 사용될 수 있는 더미 데이터
};

class DataGenerator {
public:
    DataGenerator() {
        // 시드 초기화
        srand(time(nullptr));
    }

    Data generateData() {
        Data newData;
        newData.header_info = generateHeaderInfo();
        newData.actual_data = generateActualData();
        
        // 랜덤으로 더미 데이터를 생성할지 결정
        if (rand() % 2) {
            newData.dummy_data = generateDummyData();
        } else {
            newData.dummy_data = "";
        }
        
        return newData;
    }

private:
    string generateHeaderInfo() {
        // 간단한 예로 헤더 정보를 생성
        return "Header_" + to_string(rand() % 1000);
    }

    string generateActualData() {
        // 간단한 예로 실제 데이터를 생성
        return "Data_" + to_string(rand() % 10000);
    }

    std::string generateDummyData() {
        // 간단한 예로 더미 데이터를 생성
        return "Dummy_" + std::to_string(std::rand() % 10000);
    }
};

class DataClassifier {
public:
    // 파이프라인을 설정
    void addPipeline(const string& header, const string& pipeline) {
        pipelines[header] = pipeline;
    }

    // 데이터 분류
    string classify(const Data& data) {
        if (pipelines.find(data.header_info) != pipelines.end()) {
            return pipelines[data.header_info];
        } else {
            return "default_pipeline";
        }
    }

private:
    unordered_map<string, string> pipelines;
};

class DataWarehouse {
public:
    void storeData(const string& pipeline, const Data& data) {
        warehouse[pipeline].push_back(data);
    }

    void displayWarehouse() const {
        for (const auto& entry : warehouse) {
            cout << "Pipeline: " << entry.first << endl;
            for (const auto& data : entry.second) {
                cout << "  Header: " << data.header_info << ", Data: " << data.actual_data;
                if (!data.dummy_data.empty()) {
                    cout << ", Dummy: " << data.dummy_data;
                }
                cout << endl;
            }
        }
    }

private:
    unordered_map<string, vector<Data>> warehouse;
};

int main() {
    DataGenerator generator;
    DataClassifier classifier;
    DataWarehouse warehouse;

    // 파이프라인 설정
    classifier.addPipeline("Header_1", "pipeline_1");
    classifier.addPipeline("Header_2", "pipeline_2");
    classifier.addPipeline("Header_3", "pipeline_3");

    // 예제: 10개의 데이터를 생성, 분류 및 저장
    for (int i = 0; i < 10; ++i) {
        Data data = generator.generateData();
        string pipeline = classifier.classify(data);
        warehouse.storeData(pipeline, data);
    }

    // 저장된 데이터 출력
    warehouse.displayWarehouse();
    
    return 0;
}
