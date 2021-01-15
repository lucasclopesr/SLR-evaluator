#include <grammar-constants.hpp>

SLR_Table::SLR_Table(){
    assembleAction();
    assembleGoto();
    if(DEBBUGER){
        printAction();
        std::cout << "\n\n\n\n\n\n";
        printGoto(); 
        std::cout << "\n\n\n\n\n\n";
    }
}

void SLR_Table::printAction(){
    for(int i =0; i < STATES; i++){
        std::cout << i << "    ";
        for(int j = 0; j < TERMINALS; j++){
            std::cout << this->action[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void SLR_Table::printGoto(){
    for(int i = 0; i < STATES; i++){
        std::cout << i << "    ";
        for( int j = 0; j < NON_TERMINALS; j++){
            std::cout << this->go_to[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


std::string SLR_Table::composeAction(int state, bool shift = true){
    std::string value;
    if(shift){
        value = "s-";
    } else {
        value = "r-";
    }
    value += std::to_string(state);
    return value;
}

void SLR_Table::assembleAction(){

    for(int i =0; i < STATES; i++){
        for(int j = 0; j < TERMINALS; j++){
            this->action[i][j] = ACTION_ERROR;
        }
    }

    // Transitions from state 0
    this->action[0][COMMA] = composeAction(5);
    this->action[0][RELOP] = ACTION_ERROR;
    this->action[0][SIGN] = ACTION_ERROR;
    this->action[0][ADDOP] = ACTION_ERROR;
    this->action[0][MULOP] = ACTION_ERROR;
    this->action[0][IDENTIFIER] = composeAction(7);
    this->action[0][CONSTANT] = composeAction(8);
    this->action[0][OPEN_P] = composeAction(9);
    this->action[0][CLOSE_P] = ACTION_ERROR;
    this->action[0][NOT] = composeAction(11);
    this->action[0][FUNC_IDENTIFIER] = composeAction(12);
    this->action[0][EOE] = ACTION_ERROR;

    // Transitions from state 1
    this->action[1][COMMA] =  composeAction(13);
    this->action[1][EOE] =  ACTION_ACC;

    //Transitions from state 2
    this->action[2][COMMA] = composeAction(2, false);
    this->action[2][CLOSE_P] = composeAction(2, false);
    this->action[2][EOE] = composeAction(2, false);

    //Transitions from state 3
    this->action[3][COMMA] = composeAction(3, false);
    this->action[3][RELOP] = composeAction(14);
    this->action[3][ADDOP] = composeAction(15);
    this->action[3][CLOSE_P] = composeAction(3, false);
    this->action[3][EOE] = composeAction(3, false);

    //Transitions from state 4
    this->action[4][COMMA] = composeAction(5, false);
    this->action[4][RELOP] = composeAction(5, false);
    this->action[4][SIGN] = ACTION_ERROR;
    this->action[4][ADDOP] = composeAction(16);
    this->action[4][MULOP] = ACTION_ERROR;
    this->action[4][IDENTIFIER] = ACTION_ERROR;
    this->action[4][CONSTANT] = ACTION_ERROR;
    this->action[4][OPEN_P] = ACTION_ERROR;
    this->action[4][CLOSE_P] = composeAction(5, false);
    this->action[4][NOT] = ACTION_ERROR;
    this->action[4][FUNC_IDENTIFIER] = ACTION_ERROR;
    this->action[4][EOE] = composeAction(5, false);

    //Transitions from state 5
    this->action[5][COMMA] = ACTION_ERROR;
    this->action[5][RELOP] = ACTION_ERROR;
    this->action[5][SIGN] = ACTION_ERROR;
    this->action[5][ADDOP] = ACTION_ERROR;
    this->action[5][MULOP] = ACTION_ERROR;
    this->action[5][IDENTIFIER] = composeAction(7);
    this->action[5][CONSTANT] = composeAction(8);
    this->action[5][OPEN_P] = composeAction(9);
    this->action[5][CLOSE_P] = ACTION_ERROR;
    this->action[5][NOT] = composeAction(11);
    this->action[5][FUNC_IDENTIFIER] = composeAction(12);
    this->action[5][EOE] = ACTION_ERROR;

    //Transitions from state 6
    this->action[6][COMMA] = composeAction(8, false);
    this->action[6][RELOP] = composeAction(8, false);
    this->action[6][SIGN] = ACTION_ERROR;
    this->action[6][ADDOP] = composeAction(8, false);
    this->action[6][MULOP] = composeAction(8, false);
    this->action[6][IDENTIFIER] = ACTION_ERROR;
    this->action[6][CONSTANT] = ACTION_ERROR;
    this->action[6][OPEN_P] = ACTION_ERROR;
    this->action[6][CLOSE_P] = composeAction(8, false);
    this->action[6][NOT] = ACTION_ERROR;
    this->action[6][FUNC_IDENTIFIER] = ACTION_ERROR;
    this->action[6][EOE] = composeAction(8, false);

    //Trasnitions from state 7
    this->action[7][COMMA] = composeAction(10, false);
    this->action[7][RELOP] = composeAction(10, false);
    this->action[7][SIGN] = ACTION_ERROR;
    this->action[7][ADDOP] = composeAction(10, false);
    this->action[7][MULOP] = composeAction(10, false);
    this->action[7][IDENTIFIER] = ACTION_ERROR;
    this->action[7][CONSTANT] = ACTION_ERROR;
    this->action[7][OPEN_P] = ACTION_ERROR;
    this->action[7][CLOSE_P] = composeAction(10, false);
    this->action[7][NOT] = ACTION_ERROR;
    this->action[7][FUNC_IDENTIFIER] = ACTION_ERROR;
    this->action[7][EOE] = composeAction(10, false);

    //Transition from state 8
    this->action[8][COMMA] = composeAction(11, false);
    this->action[8][RELOP] = composeAction(11, false);
    this->action[8][SIGN] = ACTION_ERROR;
    this->action[8][ADDOP] = composeAction(11, false);
    this->action[8][MULOP] = composeAction(11, false);
    this->action[8][IDENTIFIER] = ACTION_ERROR;
    this->action[8][CONSTANT] = ACTION_ERROR;
    this->action[8][OPEN_P] = ACTION_ERROR;
    this->action[8][CLOSE_P] = composeAction(11, false);
    this->action[8][NOT] = ACTION_ERROR;
    this->action[8][FUNC_IDENTIFIER] = ACTION_ERROR;
    this->action[8][EOE] = composeAction(11, false);

    //Transitions from state 9
    this->action[9][COMMA] = ACTION_ERROR;
    this->action[9][RELOP] = ACTION_ERROR;
    this->action[9][SIGN] = composeAction(5);
    this->action[9][ADDOP] = ACTION_ERROR;
    this->action[9][MULOP] = ACTION_ERROR;
    this->action[9][IDENTIFIER] = composeAction(7);
    this->action[9][CONSTANT] = composeAction(8);
    this->action[9][OPEN_P] = composeAction(9);
    this->action[9][CLOSE_P] = ACTION_ERROR;
    this->action[9][NOT] = composeAction(11);
    this->action[9][FUNC_IDENTIFIER] = composeAction(12);
    this->action[9][EOE] = ACTION_ERROR;

    //Transitions from state 10
    this->action[10][COMMA] = composeAction(13, false);
    this->action[10][RELOP] = composeAction(13, false);
    this->action[10][SIGN] = ACTION_ERROR;
    this->action[10][ADDOP] = composeAction(13, false);
    this->action[10][MULOP] = composeAction(13, false);
    this->action[10][IDENTIFIER] = ACTION_ERROR;
    this->action[10][CONSTANT] = ACTION_ERROR;
    this->action[10][OPEN_P] = ACTION_ERROR;
    this->action[10][CLOSE_P] = composeAction(13, false);
    this->action[10][NOT] = ACTION_ERROR;
    this->action[10][FUNC_IDENTIFIER] = ACTION_ERROR;
    this->action[10][EOE] = composeAction(13, false);

    //Transition from state 11
    this->action[11][COMMA] = ACTION_ERROR;
    this->action[11][RELOP] = ACTION_ERROR;
    this->action[11][SIGN] = ACTION_ERROR;
    this->action[11][ADDOP] = ACTION_ERROR;
    this->action[11][MULOP] = ACTION_ERROR;
    this->action[11][IDENTIFIER] = composeAction(7);
    this->action[11][CONSTANT] = composeAction(8);
    this->action[11][OPEN_P] = composeAction(9);
    this->action[11][CLOSE_P] = ACTION_ERROR;
    this->action[11][NOT] = composeAction(11);
    this->action[11][FUNC_IDENTIFIER] = composeAction(12);
    this->action[11][EOE] = ACTION_ERROR;


    //Transitions from state 12
    this->action[12][COMMA] = composeAction(15, false);
    this->action[12][RELOP] = composeAction(15, false);
    this->action[12][SIGN] = ACTION_ERROR;
    this->action[12][ADDOP] = composeAction(15, false);
    this->action[12][MULOP] = composeAction(15, false);
    this->action[12][IDENTIFIER] = ACTION_ERROR;
    this->action[12][CONSTANT] = ACTION_ERROR;
    this->action[12][OPEN_P] = ACTION_ERROR;
    this->action[12][CLOSE_P] = composeAction(15, false);
    this->action[12][NOT] = ACTION_ERROR;
    this->action[12][FUNC_IDENTIFIER] = ACTION_ERROR;
    this->action[12][EOE] = composeAction(15, false);

    //Transitions from state 13 
    this->action[13][COMMA] = ACTION_ERROR;
    this->action[13][RELOP] = ACTION_ERROR;
    this->action[13][SIGN] = composeAction(5);
    this->action[13][ADDOP] = ACTION_ERROR;
    this->action[13][MULOP] = ACTION_ERROR;
    this->action[13][IDENTIFIER] = composeAction(7);
    this->action[13][CONSTANT] = composeAction(8);
    this->action[13][OPEN_P] = composeAction(9);
    this->action[13][CLOSE_P] = ACTION_ERROR;
    this->action[13][NOT] = composeAction(11);
    this->action[13][FUNC_IDENTIFIER] = composeAction(12);
    this->action[13][EOE] = ACTION_ERROR;

    //Transitions from state 14
    this->action[14][COMMA] = ACTION_ERROR;
    this->action[14][RELOP] = ACTION_ERROR;
    this->action[14][SIGN] = composeAction(5);
    this->action[14][ADDOP] = ACTION_ERROR;
    this->action[14][MULOP] = ACTION_ERROR;
    this->action[14][IDENTIFIER] = composeAction(7);
    this->action[14][CONSTANT] = composeAction(8);
    this->action[14][OPEN_P] = composeAction(9);
    this->action[14][CLOSE_P] = ACTION_ERROR;
    this->action[14][NOT] = composeAction(11);
    this->action[14][FUNC_IDENTIFIER] = composeAction(12);
    this->action[14][EOE] = ACTION_ERROR;

    //Transition from state 15
    this->action[15][COMMA] = ACTION_ERROR;
    this->action[15][RELOP] = ACTION_ERROR;
    this->action[15][SIGN] = ACTION_ERROR;
    this->action[15][ADDOP] = ACTION_ERROR;
    this->action[15][MULOP] = ACTION_ERROR;
    this->action[15][IDENTIFIER] = composeAction(7);
    this->action[15][CONSTANT] = composeAction(8);
    this->action[15][OPEN_P] = composeAction(9);
    this->action[15][CLOSE_P] = ACTION_ERROR;
    this->action[15][NOT] = composeAction(11);
    this->action[15][FUNC_IDENTIFIER] = composeAction(12);
    this->action[15][EOE] = ACTION_ERROR;

    //Transition from state 16
    this->action[16][COMMA] = ACTION_ERROR;
    this->action[16][RELOP] = ACTION_ERROR;
    this->action[16][SIGN] = ACTION_ERROR;
    this->action[16][ADDOP] = ACTION_ERROR;
    this->action[16][MULOP] = ACTION_ERROR;
    this->action[16][IDENTIFIER] = composeAction(7);
    this->action[16][CONSTANT] = composeAction(8);
    this->action[16][OPEN_P] = composeAction(9);
    this->action[16][CLOSE_P] = ACTION_ERROR;
    this->action[16][NOT] = composeAction(11);
    this->action[16][FUNC_IDENTIFIER] = composeAction(12);
    this->action[16][EOE] = ACTION_ERROR;

    //Transition from state 17
    this->action[17][COMMA] = composeAction(6, false);
    this->action[17][RELOP] = composeAction(6, false);
    this->action[17][SIGN] = ACTION_ERROR;
    this->action[17][ADDOP] = composeAction(6, false);
    this->action[17][MULOP] = composeAction(16);
    this->action[17][IDENTIFIER] = ACTION_ERROR;
    this->action[17][CONSTANT] = ACTION_ERROR;
    this->action[17][OPEN_P] = ACTION_ERROR;
    this->action[17][CLOSE_P] = composeAction(6, false);
    this->action[17][NOT] = ACTION_ERROR;
    this->action[17][FUNC_IDENTIFIER] = ACTION_ERROR;
    this->action[17][EOE] = composeAction(6, false);

    //Transitions from state 18
    this->action[18][COMMA] = ACTION_ERROR;
    this->action[18][RELOP] = ACTION_ERROR;
    this->action[18][SIGN] = ACTION_ERROR;
    this->action[18][ADDOP] = ACTION_ERROR;
    this->action[18][MULOP] = ACTION_ERROR;
    this->action[18][IDENTIFIER] = ACTION_ERROR;
    this->action[18][CONSTANT] = ACTION_ERROR;
    this->action[18][OPEN_P] = ACTION_ERROR;
    this->action[18][CLOSE_P] = composeAction(25);
    this->action[18][NOT] = ACTION_ERROR;
    this->action[18][FUNC_IDENTIFIER] = ACTION_ERROR;
    this->action[18][EOE] = ACTION_ERROR;

    //Transitions from state 19
    this->action[19][COMMA] = composeAction(14, false);
    this->action[19][RELOP] = composeAction(14, false);
    this->action[19][SIGN] = ACTION_ERROR;
    this->action[19][ADDOP] = composeAction(14, false);
    this->action[19][MULOP] = composeAction(14, false);
    this->action[19][IDENTIFIER] = ACTION_ERROR;
    this->action[19][CONSTANT] = ACTION_ERROR;
    this->action[19][OPEN_P] = ACTION_ERROR;
    this->action[19][CLOSE_P] = composeAction(14, false);
    this->action[19][NOT] = ACTION_ERROR;
    this->action[19][FUNC_IDENTIFIER] = ACTION_ERROR;
    this->action[19][EOE] = composeAction(14, false);

    //Transition from state 20
    this->action[20][COMMA] = ACTION_ERROR;
    this->action[20][RELOP] = ACTION_ERROR;
    this->action[20][SIGN] = composeAction(5);
    this->action[20][ADDOP] = ACTION_ERROR;
    this->action[20][MULOP] = ACTION_ERROR;
    this->action[20][IDENTIFIER] = composeAction(7);
    this->action[20][CONSTANT] = composeAction(8);
    this->action[20][OPEN_P] = composeAction(9);
    this->action[20][CLOSE_P] = ACTION_ERROR;
    this->action[20][NOT] = composeAction(11);
    this->action[20][FUNC_IDENTIFIER] = composeAction(12);
    this->action[20][EOE] = ACTION_ERROR;

    //Transition from state 21
    this->action[21][COMMA] = composeAction(1, false);
    this->action[21][RELOP] = ACTION_ERROR;
    this->action[21][SIGN] = ACTION_ERROR;
    this->action[21][ADDOP] = ACTION_ERROR;
    this->action[21][MULOP] = ACTION_ERROR;
    this->action[21][IDENTIFIER] = ACTION_ERROR;
    this->action[21][CONSTANT] = ACTION_ERROR;
    this->action[21][OPEN_P] = ACTION_ERROR;
    this->action[21][CLOSE_P] = composeAction(1, false);
    this->action[21][NOT] = ACTION_ERROR;
    this->action[21][FUNC_IDENTIFIER] = ACTION_ERROR;
    this->action[21][EOE] = composeAction(1, false);

    //Transition from state 22
    this->action[22][COMMA] = composeAction(4, false);
    this->action[22][RELOP] = ACTION_ERROR;
    this->action[22][SIGN] = ACTION_ERROR;
    this->action[22][ADDOP] = composeAction(15);
    this->action[22][MULOP] = ACTION_ERROR;
    this->action[22][IDENTIFIER] = ACTION_ERROR;
    this->action[22][CONSTANT] = ACTION_ERROR;
    this->action[22][OPEN_P] = ACTION_ERROR;
    this->action[22][CLOSE_P] = composeAction(4, false);
    this->action[22][NOT] = ACTION_ERROR;
    this->action[22][FUNC_IDENTIFIER] = ACTION_ERROR;
    this->action[22][EOE] = composeAction(4, false);

    //Transition from state 23
    this->action[23][COMMA] = composeAction(7, false);
    this->action[23][RELOP] = composeAction(7, false);
    this->action[23][SIGN] = ACTION_ERROR;
    this->action[23][ADDOP] = composeAction(7, false);
    this->action[23][MULOP] = composeAction(16);
    this->action[23][IDENTIFIER] = ACTION_ERROR;
    this->action[23][CONSTANT] = ACTION_ERROR;
    this->action[23][OPEN_P] = ACTION_ERROR;
    this->action[23][CLOSE_P] = composeAction(7, false);
    this->action[23][NOT] = ACTION_ERROR;
    this->action[23][FUNC_IDENTIFIER] = ACTION_ERROR;
    this->action[23][EOE] = composeAction(7, false);

    //Transition from state 24
    this->action[24][COMMA] = composeAction(9, false);
    this->action[24][RELOP] = composeAction(9, false);
    this->action[24][SIGN] = ACTION_ERROR;
    this->action[24][ADDOP] = composeAction(9, false);
    this->action[24][MULOP] = composeAction(9, false);
    this->action[24][IDENTIFIER] = ACTION_ERROR;
    this->action[24][CONSTANT] = ACTION_ERROR;
    this->action[24][OPEN_P] = ACTION_ERROR;
    this->action[24][CLOSE_P] = composeAction(9, false);
    this->action[24][NOT] = ACTION_ERROR;
    this->action[24][FUNC_IDENTIFIER] = ACTION_ERROR;
    this->action[24][EOE] = composeAction(9, false);

    //Transition from state 25
    this->action[25][COMMA] = composeAction(12, false);
    this->action[25][RELOP] = composeAction(12, false);
    this->action[25][SIGN] = ACTION_ERROR;
    this->action[25][ADDOP] = composeAction(12, false);
    this->action[25][MULOP] = composeAction(12, false);
    this->action[25][IDENTIFIER] = ACTION_ERROR;
    this->action[25][CONSTANT] = ACTION_ERROR;
    this->action[25][OPEN_P] = ACTION_ERROR;
    this->action[25][CLOSE_P] = composeAction(12, false);
    this->action[25][NOT] = ACTION_ERROR;
    this->action[25][FUNC_IDENTIFIER] = ACTION_ERROR;
    this->action[25][EOE] = composeAction(12, false);

    //Transition from state 26
    this->action[26][COMMA] = composeAction(13);
    this->action[26][RELOP] = ACTION_ERROR;
    this->action[26][SIGN] = ACTION_ERROR;
    this->action[26][ADDOP] = ACTION_ERROR;
    this->action[26][MULOP] = ACTION_ERROR;
    this->action[26][IDENTIFIER] = ACTION_ERROR;
    this->action[26][CONSTANT] = ACTION_ERROR;
    this->action[26][OPEN_P] = ACTION_ERROR;
    this->action[26][CLOSE_P] = composeAction(27);
    this->action[26][NOT] = ACTION_ERROR;
    this->action[26][FUNC_IDENTIFIER] = ACTION_ERROR;
    this->action[26][EOE] = ACTION_ERROR;

    //Transition from state 27
    this->action[27][COMMA] = composeAction(16, false);
    this->action[27][RELOP] = composeAction(16, false);
    this->action[27][SIGN] = ACTION_ERROR;
    this->action[27][ADDOP] = composeAction(16, false);
    this->action[27][MULOP] = composeAction(16, false);
    this->action[27][IDENTIFIER] = ACTION_ERROR;
    this->action[27][CONSTANT] = ACTION_ERROR;
    this->action[27][OPEN_P] = ACTION_ERROR;
    this->action[27][CLOSE_P] = composeAction(16, false);
    this->action[27][NOT] = ACTION_ERROR;
    this->action[27][FUNC_IDENTIFIER] = ACTION_ERROR;
    this->action[27][EOE] = composeAction(16, false);

}

void SLR_Table::assembleGoto(){
        for(int i =0; i < STATES; i++){
        for(int j = 0; j < NON_TERMINALS; j++){
            this->go_to[i][j] = GOTO_ERROR;
        }
    }

        // Transitions from state 0
    this->go_to[0][EXPR_EXP] = GOTO_ERROR;
    this->go_to[0][EXPR_LIST] = 1;
    this->go_to[0][EXPR] = 2;
    this->go_to[0][SIMPLE_EXPR] = 3;
    this->go_to[0][TERM] = 4;
    this->go_to[0][FACTOR] = 6;
    this->go_to[0][FUNCTION_REF] = 10;

    // Transitions from state 5
    this->go_to[5][EXPR_EXP] = GOTO_ERROR;
    this->go_to[5][EXPR_LIST] = GOTO_ERROR;
    this->go_to[5][EXPR] = GOTO_ERROR;
    this->go_to[5][SIMPLE_EXPR] = GOTO_ERROR;
    this->go_to[5][TERM] = 17;
    this->go_to[5][FACTOR] = 6;
    this->go_to[5][FUNCTION_REF] = 10;

    // Transitions from state 9
    this->go_to[9][EXPR_EXP] = GOTO_ERROR;
    this->go_to[9][EXPR_LIST] = GOTO_ERROR;
    this->go_to[9][EXPR] = 18;
    this->go_to[9][SIMPLE_EXPR] = 3;
    this->go_to[9][TERM] = 4;
    this->go_to[9][FACTOR] = 6;
    this->go_to[9][FUNCTION_REF] = 10;

    // Transitions from state 11
    this->go_to[11][EXPR_EXP] = GOTO_ERROR;
    this->go_to[11][EXPR_LIST] = GOTO_ERROR;
    this->go_to[11][EXPR] = GOTO_ERROR;
    this->go_to[11][SIMPLE_EXPR] = GOTO_ERROR;
    this->go_to[11][TERM] = GOTO_ERROR;
    this->go_to[11][FACTOR] = 19;
    this->go_to[11][FUNCTION_REF] = 10;

        // Transitions from state 13
    this->go_to[13][EXPR_EXP] = GOTO_ERROR;
    this->go_to[13][EXPR_LIST] = GOTO_ERROR;
    this->go_to[13][EXPR] = 21;
    this->go_to[13][SIMPLE_EXPR] = 3;
    this->go_to[13][TERM] = 4;
    this->go_to[13][FACTOR] = 6;
    this->go_to[13][FUNCTION_REF] = 10;

        // Transitions from state 14
    this->go_to[14][EXPR_EXP] = GOTO_ERROR;
    this->go_to[14][EXPR_LIST] = GOTO_ERROR;
    this->go_to[14][EXPR] = GOTO_ERROR;
    this->go_to[14][SIMPLE_EXPR] = 22;
    this->go_to[14][TERM] = 4;
    this->go_to[14][FACTOR] = 6;
    this->go_to[14][FUNCTION_REF] = 10;

        // Transitions from state 15
    this->go_to[15][EXPR_EXP] = GOTO_ERROR;
    this->go_to[15][EXPR_LIST] = GOTO_ERROR;
    this->go_to[15][EXPR] = GOTO_ERROR;
    this->go_to[15][SIMPLE_EXPR] = GOTO_ERROR;
    this->go_to[15][TERM] = 23;
    this->go_to[15][FACTOR] = 6;
    this->go_to[15][FUNCTION_REF] = 10;

    // Transitions from state 16
    this->go_to[16][EXPR_EXP] = GOTO_ERROR;
    this->go_to[16][EXPR_LIST] = GOTO_ERROR;
    this->go_to[16][EXPR] = GOTO_ERROR;
    this->go_to[16][SIMPLE_EXPR] = GOTO_ERROR;
    this->go_to[16][TERM] = GOTO_ERROR;
    this->go_to[16][FACTOR] = 24;
    this->go_to[16][FUNCTION_REF] = 10;

    // Transitions from state 20
    this->go_to[20][EXPR_EXP] = GOTO_ERROR;
    this->go_to[20][EXPR_LIST] = 26;
    this->go_to[20][EXPR] = 2;
    this->go_to[20][SIMPLE_EXPR] = 3;
    this->go_to[20][TERM] = 4;
    this->go_to[20][FACTOR] = 6;
    this->go_to[20][FUNCTION_REF] = 10;
}

std::tuple<char,int> SLR_Table::get_action(int state, int terminal){
    std::string action = this->action[state][terminal];
    
    if(action.length() == 1){
        if(action.at(0) == ACTION_ACC){
            return std::tuple<char,int>{ACTION_ACC, GOTO_ERROR};
        }
        return std::tuple<char,int>{ACTION_ERROR, GOTO_ERROR};
    }

    char act = action.at(0);
    action.erase(0,2);
    int new_state = std::stoi(action);
    return std::tuple<char,int>{act, new_state};
}

int SLR_Table::get_go_to(int state, int nterminal){
    int new_state = this->go_to[state][nterminal];
    return new_state;
}