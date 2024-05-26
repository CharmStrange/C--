#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

// 데이터 구조체 정의
struct Data {
    std::string header_info;
    std::string actual_data;
    std::string dummy_data; // 필요에 따라 사용될 수 있는 더미 데이터
};

class DataGenerator {
public:
    DataGenerator() {
        // 시드 초기화
        std::srand(std::time(nullptr));
    }

    Data generateData() {
        Data newData;
        newData.header_info = generateHeaderInfo();
        newData.actual_data = generateActualData();
        
        // 랜덤으로 더미 데이터를 생성할지 결정
        if (std::rand() % 2) {
            newData.dummy_data = generateDummyData();
        } else {
            newData.dummy_data = "";
        }
        
        return newData;
    }

private:
    std::string generateHeaderInfo() {
        // 간단한 예로 헤더 정보를 생성
        return "Header_" + std::to_string(std::rand() % 1000);
    }

    std::string generateActualData() {
        // 간단한 예로 실제 데이터를 생성
        return "Data_" + std::to_string(std::rand() % 10000);
    }

    std::string generateDummyData() {
        // 간단한 예로 더미 데이터를 생성
        return "Dummy_" + std::to_string(std::rand() % 10000);
    }
};

class DataClassifier {
public:
    // 파이프라인을 설정
    void addPipeline(const std::string& header, const std::string& pipeline) {
        pipelines[header] = pipeline;
    }

    // 데이터 분류
    std::string classify(const Data& data) {
        if (pipelines.find(data.header_info) != pipelines.end()) {
            return pipelines[data.header_info];
        } else {
            return "default_pipeline";
        }
    }

private:
    std::unordered_map<std::string, std::string> pipelines;
};

class DataWarehouse {
public:
    void storeData(const std::string& pipeline, const Data& data) {
        warehouse[pipeline].push_back(data);
    }

    void displayWarehouse() const {
        for (const auto& entry : warehouse) {
            std::cout << "Pipeline: " << entry.first << std::endl;
            for (const auto& data : entry.second) {
                std::cout << "  Header: " << data.header_info << ", Data: " << data.actual_data;
                if (!data.dummy_data.empty()) {
                    std::cout << ", Dummy: " << data.dummy_data;
                }
                std::cout << std::endl;
            }
        }
    }

private:
    std::unordered_map<std::string, std::vector<Data>> warehouse;
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
        std::string pipeline = classifier.classify(data);
        warehouse.storeData(pipeline, data);
    }

    // 저장된 데이터 출력
    warehouse.displayWarehouse();
    
    return 0;
}
