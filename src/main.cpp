#include <SLR-parser.hpp>

int main(){
    SLR_Parser parser;
    std::vector<int> input;
    input.push_back(IDENTIFIER);
    input.push_back(ADDOP);
    input.push_back(OPEN_P);
    input.push_back(IDENTIFIER);
    input.push_back(MULOP);
    input.push_back(IDENTIFIER);
    input.push_back(CLOSE_P);
    if(parser.parse(input)){
        std::cout << "VAMODALEPORAAAAAAAA" << std::endl;
    }
    return 0;
}