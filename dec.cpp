#include <iostream>
#include <vector>

namespace decoding{
std::vector<std::string> first_method(std::vector<std::string> content){
    std::vector<std::string> decoded_text;
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
                symb = char((~int(line[i]))-20);
                temp.push_back(symb);
            }
        }
        decoded_text.push_back(temp);
    }
    std::cout << "File was decoded" << std::endl;
    return decoded_text;
}
std::vector<std::string> second_method(std::vector<std::string> content){
    std::vector<std::string> temp_cont;
    for(std::string l : content){
        std::string temp_line;
        for(char t : l){
            temp_line.push_back(char(~int(t)));
        }
        temp_cont.push_back(temp_line);
    }
    
    std::vector<std::string> decoded_text;



    for(std::string line : temp_cont){
        std::string temp;
        std::string three;
        for(int i=0; i<=line.size(); i++){
            char *end;
            if(three.size() != 3) three.push_back(line[i]);
            else{
                //std::cout << three << std::endl;
                //const char *three_char = three.c_str(); -> string to char[]
                int ascii_code = strtol(three.c_str(), &end, 10);
                temp.push_back(char(ascii_code));
                three = "";
                --i;
            }
        }
        decoded_text.push_back(temp);
    }
    std::cout << "File was decoded" << std::endl;
    return decoded_text;
    }
};