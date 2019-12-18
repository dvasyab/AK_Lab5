#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> readFile(std::string fileName){
    std::fstream inFile;
    std::vector<std::string> content;

    inFile.open(fileName, std::ios::in);

    if(inFile.is_open()){
        std::string line;
 
        while(inFile){
            getline(inFile, line);
            if(!inFile) break;
            content.push_back(line);
            }
        inFile.close();
    }

    else{
        std::cout << "Cannot open file: " << fileName << std::endl;
    }

    return content;
}

void wrightingToFile(std::string fileName,std::vector<std::string> content){
    std::ofstream outFile;
    outFile.open(fileName);
    if(outFile.is_open()){
        for(std::string line : content){
            outFile << line << std::endl;
        }
    }
    else{
        std::cout << "Cannot open file: " << fileName << std::endl;
    }
}