#include <iostream>
//#include <vector> 
//#include <algorithm>
//#include <fstream>

#include "enc.cpp"
#include "dec.cpp"
#include "working_with_file.cpp"

int main(int Narg, char **argv) {
    if (std::string(argv[1]) == std::string("-h")){
        std::cout << "This program was made for encoding and decoding txt files in english\n";
        std::cout << "./main [-type] [method]\n";
        std::cout << "-type:\n  -e for encoding\n  -d for decoding\n";
        std::cout << "method:\n  1 or 2\nOr type -h to get this help :)\n";
        return 0;
    }

    std::string fileName;
    if(Narg == 4){
        fileName = argv[3];
    }
    else{
        std::cout << "Wrong parametrs are given\n" << std::endl;
        return 0;
    }

    std::vector<std::string> content = readFile(fileName);
    //encoding
    if(std::string(argv[1]) == std::string("-e")){
        if(std::string(argv[2]) == std::string("1")) content = encoding::first_method(content);
        else if (std::string(argv[2]) == std::string("2")) content = encoding::second_method(content);
        }
    //decoding
    else if (std::string(argv[1]) == std::string("-d")){
        if(std::string(argv[2]) == std::string("1")) content = decoding::first_method(content);
        else if (std::string(argv[2]) == std::string("2")) content = decoding::second_method(content);
    }
    //Wrong keyword
    else{
        std::cout << "Wrong parametrs are given\n" << std::endl;
        return 0;
    }

    wrightingToFile(fileName, content);
    return 0;
}