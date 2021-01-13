#include <grammar-constants.hpp>

SLR_Table::SLR_Table(){
    assembleAction();
    assembleGoto();
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
    this->action[0][SIGN] = composeAction(4);
    this->action[0][IDENTIFIER] = composeAction(6);
    this->action[0][CONSTANT] = composeAction(7);
    this->action[0][OPEN_P] = composeAction(8);
    this->action[0][NOT] = composeAction(10);
    this->action[0][FUNC_IDENTIFIER] = composeAction(11);

    // Transitions from state 1
    this->action[1][EOE] =  ACTION_ACC;

    //Transitions from state 2
    this->action[2][RELOP] = composeAction(12);
    this->action[2][ADDOP] = composeAction(13);
    this->action[2][CLOSE_P] = composeAction(1, false);
    this->action[2][EOE] = composeAction(1, false);

    //Transitions from state 3
    this->action[3][RELOP] = composeAction(3, false);
    this->action[3][ADDOP] = composeAction(3, false);
    this->action[3][MULOP] = composeAction(14);
    this->action[3][CLOSE_P] = composeAction(3, false);
    this->action[3][EOE] = composeAction(3, false);

    //Transitions from state 4
    this->action[4][IDENTIFIER] = composeAction(6);
    this->action[4][CONSTANT] = composeAction(7);
    this->action[4][OPEN_P] = composeAction(8);
    this->action[4][NOT] = composeAction(10);
    this->action[4][FUNC_IDENTIFIER] = composeAction(11);

    //Transitions from state 5
    this->action[5][RELOP] = composeAction(6, false);
    this->action[5][ADDOP] = composeAction(6, false);
    this->action[5][MULOP] = composeAction(6, false);
    this->action[5][CLOSE_P] = composeAction(6, false);
    this->action[5][EOE] = composeAction(6, false);

    //Transitions from state 6
    this->action[6][RELOP] = composeAction(8, false);
    this->action[6][ADDOP] = composeAction(8, false);
    this->action[6][MULOP] = composeAction(8, false);
    this->action[6][CLOSE_P] = composeAction(8, false);
    this->action[6][EOE] = composeAction(8, false);

    //Trasnitions from state 7
    this->action[7][RELOP] = composeAction(9, false);
    this->action[7][ADDOP] = composeAction(9, false);
    this->action[7][MULOP] = composeAction(9, false);
    this->action[7][CLOSE_P] = composeAction(9, false);
    this->action[7][EOE] = composeAction(9, false);

    //Transition from state 8
    this->action[8][SIGN] = composeAction(4);
    this->action[8][IDENTIFIER] = composeAction(6);
    this->action[8][CONSTANT] = composeAction(7);
    this->action[8][OPEN_P] = composeAction(8);
    this->action[8][NOT] = composeAction(10);
    this->action[8][FUNC_IDENTIFIER] = composeAction(11);

    //Transitions from state 9
    this->action[9][RELOP] = composeAction(11, false);
    this->action[9][ADDOP] = composeAction(11, false);
    this->action[9][MULOP] = composeAction(11, false);
    this->action[9][CLOSE_P] = composeAction(11, false);
    this->action[9][EOE] = composeAction(11, false);

    //Transitions from state 10
    this->action[10][IDENTIFIER] = composeAction(6);
    this->action[10][CONSTANT] = composeAction(7);
    this->action[10][OPEN_P] = composeAction(8);
    this->action[10][NOT] = composeAction(10);
    this->action[10][FUNC_IDENTIFIER] = composeAction(11);

    //Transition from state 11
    this->action[11][RELOP] = composeAction(13, false);
    this->action[11][ADDOP] = composeAction(13, false);
    this->action[11][MULOP] = composeAction(13, false);
    this->action[11][OPEN_P] = composeAction(18);
    this->action[11][CLOSE_P] = composeAction(13, false);
    this->action[11][EOE] = composeAction(13, false);

    //Transitions from state 12
    this->action[12][SIGN] = composeAction(4);
    this->action[12][IDENTIFIER] = composeAction(6);
    this->action[12][CONSTANT] = composeAction(7);
    this->action[12][OPEN_P] = composeAction(8);
    this->action[12][NOT] = composeAction(10);
    this->action[12][FUNC_IDENTIFIER] = composeAction(11);

    //Transitions from state 13 
    this->action[13][IDENTIFIER] = composeAction(6);
    this->action[13][CONSTANT] = composeAction(7);
    this->action[13][OPEN_P] = composeAction(8);
    this->action[13][NOT] = composeAction(10);
    this->action[13][FUNC_IDENTIFIER] = composeAction(11);

    //Transitions from state 14
    this->action[14][IDENTIFIER] = composeAction(6);
    this->action[14][CONSTANT] = composeAction(7);
    this->action[14][OPEN_P] = composeAction(8);
    this->action[14][NOT] = composeAction(10);
    this->action[14][FUNC_IDENTIFIER] = composeAction(11);

    //Transition from state 15
    this->action[15][RELOP] = composeAction(4, false);
    this->action[15][ADDOP] = composeAction(4, false);
    this->action[15][MULOP] = composeAction(14);
    this->action[15][CLOSE_P] = composeAction(4, false);
    this->action[15][EOE] = composeAction(4, false);

    //Transition from state 16
    this->action[16][CLOSE_P] = composeAction(22);

    //Transition from state 17
    this->action[17][RELOP] = composeAction(12, false);
    this->action[17][ADDOP] = composeAction(12, false);
    this->action[17][MULOP] = composeAction(12, false);
    this->action[17][CLOSE_P] = composeAction(12, false);
    this->action[17][EOE] = composeAction(12, false);

    //Transitions from state 18
    this->action[18][SIGN] = composeAction(4);
    this->action[18][IDENTIFIER] = composeAction(6);
    this->action[18][CONSTANT] = composeAction(7);
    this->action[18][OPEN_P] = composeAction(8);
    this->action[18][NOT] = composeAction(10);
    this->action[18][FUNC_IDENTIFIER] = composeAction(11);

    //Transitions from state 19
    this->action[19][ADDOP] = composeAction(13);
    this->action[19][CLOSE_P] = composeAction(2, false);
    this->action[19][EOE] = composeAction(2, false);

    //Transition from state 20
    this->action[20][RELOP] = composeAction(5, false);
    this->action[20][ADDOP] = composeAction(5, false);
    this->action[20][MULOP] = composeAction(14);
    this->action[20][CLOSE_P] = composeAction(5, false);
    this->action[20][EOE] = composeAction(5, false);

    //Transition from state 21
    this->action[21][RELOP] = composeAction(7, false);
    this->action[21][ADDOP] = composeAction(7, false);
    this->action[21][MULOP] = composeAction(7, false);
    this->action[21][CLOSE_P] = composeAction(7, false);
    this->action[21][EOE] = composeAction(7, false);

    //Transition from state 22
    this->action[22][RELOP] = composeAction(10, false);
    this->action[22][ADDOP] = composeAction(10, false);
    this->action[22][MULOP] = composeAction(10, false);
    this->action[22][CLOSE_P] = composeAction(10, false);
    this->action[22][EOE] = composeAction(10, false);

    //Transition from state 23
    this->action[23][CLOSE_P] = composeAction(24);

    //Transition from state 24
    this->action[24][RELOP] = composeAction(14, false);
    this->action[24][ADDOP] = composeAction(14, false);
    this->action[24][MULOP] = composeAction(14, false);
    this->action[24][CLOSE_P] = composeAction(14, false);
    this->action[24][EOE] = composeAction(14, false);

}

void SLR_Table::assembleGoto(){
        for(int i =0; i < STATES; i++){
        for(int j = 0; j < NON_TERMINALS; j++){
            this->go_to[i][j] = GOTO_ERROR;
        }
    }

        // Transitions from state 0
    this->go_to[0][EXPR] = 1;
    this->go_to[0][SIMPLE_EXPR] = 2;
    this->go_to[0][TERM] = 3;
    this->go_to[0][FACTOR] = 5;
    this->go_to[0][FUNCTION_REF] = 9;

    // Transitions from state 4
    this->go_to[4][TERM] = 15;
    this->go_to[4][FACTOR] = 5;
    this->go_to[4][FUNCTION_REF] = 9;

    // Transitions from state 8
    this->go_to[8][EXPR] = 16;
    this->go_to[8][SIMPLE_EXPR] = 2;
    this->go_to[8][TERM] = 3;
    this->go_to[8][FACTOR] = 5;
    this->go_to[8][FUNCTION_REF] = 9;

    // Transitions from state 10
    this->go_to[10][FACTOR] = 17;
    this->go_to[10][FUNCTION_REF] = 9;

        // Transitions from state 12
    this->go_to[12][SIMPLE_EXPR] = 19;
    this->go_to[12][TERM] = 3;
    this->go_to[12][FACTOR] = 5;
    this->go_to[12][FUNCTION_REF] = 9;

        // Transitions from state 13
    this->go_to[13][TERM] = 20;
    this->go_to[13][FACTOR] = 5;
    this->go_to[13][FUNCTION_REF] = 9;

        // Transitions from state 14
    this->go_to[14][FACTOR] = 21;
    this->go_to[14][FUNCTION_REF] = 9;

        // Transitions from state 18
    this->go_to[18][EXPR] = 23;
    this->go_to[18][SIMPLE_EXPR] = 2;
    this->go_to[18][TERM] = 3;
    this->go_to[18][FACTOR] = 5;
    this->go_to[18][FUNCTION_REF] = 9;
}

