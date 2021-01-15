#ifndef SLR_TABLE
#define SLR_TABLE

#include <string>
#include <tuple>
#include <iostream>

#define DEBBUGER true

// //Terminal symbol's
// #define TERMINALS 11
// #define RELOP 0
// #define SIGN 1
// #define ADDOP 2
// #define MULOP 3
// #define IDENTIFIER 4
// #define CONSTANT 5
// #define OPEN_P 6 // (
// #define CLOSE_P 7 // )
// #define NOT 8
// #define FUNC_IDENTIFIER 9
// #define EOE 10 // $

// //Non-terminal symbol's
// #define NON_TERMINALS 6
// #define EXPR_EXP 0
// #define EXPR 1
// #define SIMPLE_EXPR 2
// #define TERM 3
// #define FACTOR 4
// #define FUNCTION_REF 5

// #define STATES 25 // Number of states in the grammars SLR table

//Terminal symbol's
#define TERMINALS 12
#define COMMA 0
#define RELOP 1
#define SIGN 2
#define ADDOP 3
#define MULOP 4
#define IDENTIFIER 5
#define CONSTANT 6
#define OPEN_P 7 // (
#define CLOSE_P 8 // )
#define NOT 9
#define FUNC_IDENTIFIER 10
#define EOE 11 // $

//Non-terminal symbol's
#define NON_TERMINALS 7
#define EXPR_EXP 0
#define EXPR_LIST 1
#define EXPR 2
#define SIMPLE_EXPR 3
#define TERM 4
#define FACTOR 5
#define FUNCTION_REF 6

#define STATES 28 // Number of states in the grammars SLR table

#define ACTION_ERROR '-'
#define ACTION_ACC 'a'

#define GOTO_ERROR -1


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