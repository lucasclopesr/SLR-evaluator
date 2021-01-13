#ifndef SINTAX_PARSER
#define SINTAX_PARSER

#include <vector>
#include <grammar-constants.hpp>

class SLRParser {
    SLR_Table::SLR_Table table;
    std::vector<int> state_stack;
    std::vector<std::string> symbol_stack;
    public:
        SLRParser();
};

#endif