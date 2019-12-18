#include <iostream>
#include <vector>

namespace encoding{
std::vector<std::string> first_method(std::vector<std::string> content){
    std::vector<std::string> encoded_text;
    for(std::string line : content){
        std::string temp;
        for(int i=0; i<line.size(); i++){
            char symb;
            if(i%2 == 0){
                symb = char(~(int(line[i])));
                temp.push_back(symb);
            } 
            else
            {
                symb = char(~(int(line[i])+20));
                temp.push_back(symb);              
            }
        }
        encoded_text.push_back(temp);
    }
    std::cout << "File was encoded" << std::endl;
    return encoded_text;
}

std::vector<std::string> second_method(std::vector<std::string> content){
    std::vector<std::string> temp_cont;

    for(std::string line : content){
        std::string temp_line;
        for(char i : line){
            std::string temp_three;
            if(int(i) >=100) temp_three.append(std::to_string(int(i)));
            else
            {
                temp_three.append("0");
                temp_three.append(std::to_string(int(i)));
            }
            std::cout << char(-12110)<< " ";
            temp_line.append(temp_three);
        }
        temp_cont.push_back(temp_line);
    }
    
    std::vector<std::string> encoded_text;
    for(std::string l : temp_cont){
        std::string temp_line;
        for(char t : l){
            temp_line.push_back(char(~int(t)));
        }
        encoded_text.push_back(temp_line);
    }

    std::cout << "File was encoded" << std::endl;
    return encoded_text;
    }
};