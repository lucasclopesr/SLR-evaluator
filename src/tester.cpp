#include <SLR-parser.hpp>

int main(){

    SLR_Parser parser;

    std::vector<int> input_string;

    input_string.push_back(5);
    input_string.push_back(3);
    input_string.push_back(5);
    if(parser.parse(input_string)){
        std::cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
    }

}