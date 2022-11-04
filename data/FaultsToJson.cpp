//
// Created by brent on 3/11/22.
//

#include <fstream>
#include "FaultsToJson.h"

void faultVectorToJsonFile(const std::vector<int>& faults){
    std::ofstream outFile("faults.json");
    outFile << "[";
    for(int i = 0; i < faults.size() - 1; i++){
        outFile << faults.at(i) << ", ";
    }
    outFile << faults.at(faults.size() - 1);
    outFile << "]";
    outFile.close();
}