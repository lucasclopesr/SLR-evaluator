#ifndef SLR_TABLE
#define SLR_TABLE

#include <string>
#include <iostream>

//Terminal symbol's
#define TERMINALS 11
#define RELOP 0
#define SIGN 1
#define ADDOP 2
#define MULOP 3
#define IDENTIFIER 4
#define CONSTANT 5
#define OPEN_P 6 // (
#define CLOSE_P 7 // )
#define NOT 8
#define FUNC_IDENTIFIER 9
#define EOE 10 // $

//Non-terminal symbol's
#define NON_TERMINALS 6
#define EXPR_EXP 0
#define EXPR 1
#define SIMPLE_EXPR 2
#define TERM 3
#define FACTOR 4
#define FUNCTION_REF 5

#define STATES 25 // Number of states in the grammars SLR table

#define ACTION_ERROR "-"
#define ACTION_ACC "Acc"

#define GOTO_ERROR -1


class SLR_Table {
    public:
        std::string action[STATES][TERMINALS];
        int go_to[STATES][NON_TERMINALS];
        SLR_Table();
        void printAction();
        void printGoto();
    private:
        std::string composeAction(int , bool );
        void assembleAction();
        void assembleGoto();
};

#endif