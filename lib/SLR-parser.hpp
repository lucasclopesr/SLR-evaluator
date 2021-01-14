#ifndef SINTAX_PARSER
#define SINTAX_PARSER

#include <vector>
#include <grammar-constants.hpp>

#define ENTRY_STATE 0

class SLR_Parser {
    SLR_Table *table;
    std::vector<int> state_stack;
    std::vector<int> symbol_stack;
    public:
        SLR_Parser();
        bool parse(std::vector<int>);
    private:
        bool reduce(int); 
        void parse_action(std::string);
};

#endif