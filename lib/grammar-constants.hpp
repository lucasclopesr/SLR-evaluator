#ifndef SLR_TABLE
#define SLR_TABLE

#include <string>
#include <tuple>
#include <iostream>
#include <grammar.hpp>


class SLR_Table {
    public:
        SLR_Table();
        void printAction();
        void printGoto();
        std::tuple<char, int> get_action(int, int);
        int get_go_to(int, int);
    private:
        std::string action[STATES][TERMINALS];
        int go_to[STATES][NON_TERMINALS];
        std::string composeAction(int, bool );
        void assembleAction();
        void assembleGoto();
};

#endif