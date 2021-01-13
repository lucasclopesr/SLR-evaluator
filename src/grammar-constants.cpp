#include <grammar-constants.hpp>

SLR_Table::SLR_Table(){
    assembleAction();
    assembleGoto();
}

void SLR_Table::printAction(){
    for(int i =0; i < STATES; i++){
        std::cout << i << "    ";
        for(int j = 0; j < TERMINALS; j++){
            std::cout << this->Action[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void SLR_Table::printGoto(){
    for(int i = 0; i < STATES; i++){
        std::cout << i << "    ";
        for( int j = 0; j < NON_TERMINALS; j++){
            std::cout << this->Goto[i][j] << " ";
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
            this->Action[i][j] = ACTION_ERROR;
        }
    }

    // Transitions from state 0
    this->Action[0][SIGN] = composeAction(4);
    this->Action[0][IDENTIFIER] = composeAction(6);
    this->Action[0][CONSTANT] = composeAction(7);
    this->Action[0][OPEN_P] = composeAction(8);
    this->Action[0][NOT] = composeAction(10);
    this->Action[0][FUNC_IDENTIFIER] = composeAction(11);

    // Transitions from state 1
    this->Action[1][EOE] =  ACTION_ACC;

    //Transitions from state 2
    this->Action[2][RELOP] = composeAction(12);
    this->Action[2][ADDOP] = composeAction(13);
    this->Action[2][CLOSE_P] = composeAction(1, false);
    this->Action[2][EOE] = composeAction(1, false);

    //Transitions from state 3
    this->Action[3][RELOP] = composeAction(3, false);
    this->Action[3][ADDOP] = composeAction(3, false);
    this->Action[3][MULOP] = composeAction(14);
    this->Action[3][CLOSE_P] = composeAction(3, false);
    this->Action[3][EOE] = composeAction(3, false);

    //Transitions from state 4
    this->Action[4][IDENTIFIER] = composeAction(6);
    this->Action[4][CONSTANT] = composeAction(7);
    this->Action[4][OPEN_P] = composeAction(8);
    this->Action[4][NOT] = composeAction(10);
    this->Action[4][FUNC_IDENTIFIER] = composeAction(11);

    //Transitions from state 5
    this->Action[5][RELOP] = composeAction(6, false);
    this->Action[5][ADDOP] = composeAction(6, false);
    this->Action[5][MULOP] = composeAction(6, false);
    this->Action[5][CLOSE_P] = composeAction(6, false);
    this->Action[5][EOE] = composeAction(6, false);

    //Transitions from state 6
    this->Action[6][RELOP] = composeAction(8, false);
    this->Action[6][ADDOP] = composeAction(8, false);
    this->Action[6][MULOP] = composeAction(8, false);
    this->Action[6][CLOSE_P] = composeAction(8, false);
    this->Action[6][EOE] = composeAction(8, false);

    //Trasnitions from state 7
    this->Action[7][RELOP] = composeAction(9, false);
    this->Action[7][ADDOP] = composeAction(9, false);
    this->Action[7][MULOP] = composeAction(9, false);
    this->Action[7][CLOSE_P] = composeAction(9, false);
    this->Action[7][EOE] = composeAction(9, false);

    //Transition from state 8
    this->Action[8][SIGN] = composeAction(4);
    this->Action[8][IDENTIFIER] = composeAction(6);
    this->Action[8][CONSTANT] = composeAction(7);
    this->Action[8][OPEN_P] = composeAction(8);
    this->Action[8][NOT] = composeAction(10);
    this->Action[8][FUNC_IDENTIFIER] = composeAction(11);

    //Transitions from state 9
    this->Action[9][RELOP] = composeAction(11, false);
    this->Action[9][ADDOP] = composeAction(11, false);
    this->Action[9][MULOP] = composeAction(11, false);
    this->Action[9][CLOSE_P] = composeAction(11, false);
    this->Action[9][EOE] = composeAction(11, false);

    //Transitions from state 10
    this->Action[10][IDENTIFIER] = composeAction(6);
    this->Action[10][CONSTANT] = composeAction(7);
    this->Action[10][OPEN_P] = composeAction(8);
    this->Action[10][NOT] = composeAction(10);
    this->Action[10][FUNC_IDENTIFIER] = composeAction(11);

    //Transition from state 11
    this->Action[11][RELOP] = composeAction(13, false);
    this->Action[11][ADDOP] = composeAction(13, false);
    this->Action[11][MULOP] = composeAction(13, false);
    this->Action[11][OPEN_P] = composeAction(18);
    this->Action[11][CLOSE_P] = composeAction(13, false);
    this->Action[11][EOE] = composeAction(13, false);

    //Transitions from state 12
    this->Action[12][SIGN] = composeAction(4);
    this->Action[12][IDENTIFIER] = composeAction(6);
    this->Action[12][CONSTANT] = composeAction(7);
    this->Action[12][OPEN_P] = composeAction(8);
    this->Action[12][NOT] = composeAction(10);
    this->Action[12][FUNC_IDENTIFIER] = composeAction(11);

    //Transitions from state 13 
    this->Action[13][IDENTIFIER] = composeAction(6);
    this->Action[13][CONSTANT] = composeAction(7);
    this->Action[13][OPEN_P] = composeAction(8);
    this->Action[13][NOT] = composeAction(10);
    this->Action[13][FUNC_IDENTIFIER] = composeAction(11);

    //Transitions from state 14
    this->Action[14][IDENTIFIER] = composeAction(6);
    this->Action[14][CONSTANT] = composeAction(7);
    this->Action[14][OPEN_P] = composeAction(8);
    this->Action[14][NOT] = composeAction(10);
    this->Action[14][FUNC_IDENTIFIER] = composeAction(11);

    //Transition from state 15
    this->Action[15][RELOP] = composeAction(4, false);
    this->Action[15][ADDOP] = composeAction(4, false);
    this->Action[15][MULOP] = composeAction(14);
    this->Action[15][CLOSE_P] = composeAction(4, false);
    this->Action[15][EOE] = composeAction(4, false);

    //Transition from state 16
    this->Action[16][CLOSE_P] = composeAction(22);

    //Transition from state 17
    this->Action[17][RELOP] = composeAction(12, false);
    this->Action[17][ADDOP] = composeAction(12, false);
    this->Action[17][MULOP] = composeAction(12, false);
    this->Action[17][CLOSE_P] = composeAction(12, false);
    this->Action[17][EOE] = composeAction(12, false);

    //Transitions from state 18
    this->Action[18][SIGN] = composeAction(4);
    this->Action[18][IDENTIFIER] = composeAction(6);
    this->Action[18][CONSTANT] = composeAction(7);
    this->Action[18][OPEN_P] = composeAction(8);
    this->Action[18][NOT] = composeAction(10);
    this->Action[18][FUNC_IDENTIFIER] = composeAction(11);

    //Transitions from state 19
    this->Action[19][ADDOP] = composeAction(13);
    this->Action[19][CLOSE_P] = composeAction(2, false);
    this->Action[19][EOE] = composeAction(2, false);

    //Transition from state 20
    this->Action[20][RELOP] = composeAction(5, false);
    this->Action[20][ADDOP] = composeAction(5, false);
    this->Action[20][MULOP] = composeAction(14);
    this->Action[20][CLOSE_P] = composeAction(5, false);
    this->Action[20][EOE] = composeAction(5, false);

    //Transition from state 21
    this->Action[21][RELOP] = composeAction(7, false);
    this->Action[21][ADDOP] = composeAction(7, false);
    this->Action[21][MULOP] = composeAction(7, false);
    this->Action[21][CLOSE_P] = composeAction(7, false);
    this->Action[21][EOE] = composeAction(7, false);

    //Transition from state 22
    this->Action[22][RELOP] = composeAction(10, false);
    this->Action[22][ADDOP] = composeAction(10, false);
    this->Action[22][MULOP] = composeAction(10, false);
    this->Action[22][CLOSE_P] = composeAction(10, false);
    this->Action[22][EOE] = composeAction(10, false);

    //Transition from state 23
    this->Action[23][CLOSE_P] = composeAction(24);

    //Transition from state 24
    this->Action[24][RELOP] = composeAction(14, false);
    this->Action[24][ADDOP] = composeAction(14, false);
    this->Action[24][MULOP] = composeAction(14, false);
    this->Action[24][CLOSE_P] = composeAction(14, false);
    this->Action[24][EOE] = composeAction(14, false);

}

void SLR_Table::assembleGoto(){
        for(int i =0; i < STATES; i++){
        for(int j = 0; j < NON_TERMINALS; j++){
            this->Goto[i][j] = GOTO_ERROR;
        }
    }

        // Transitions from state 0
    this->Goto[0][EXPR] = 1;
    this->Goto[0][SIMPLE_EXPR] = 2;
    this->Goto[0][TERM] = 3;
    this->Goto[0][FACTOR] = 5;
    this->Goto[0][FUNCTION_REF] = 9;

    // Transitions from state 4
    this->Goto[4][TERM] = 15;
    this->Goto[4][FACTOR] = 5;
    this->Goto[4][FUNCTION_REF] = 9;

    // Transitions from state 8
    this->Goto[8][EXPR] = 16;
    this->Goto[8][SIMPLE_EXPR] = 2;
    this->Goto[8][TERM] = 3;
    this->Goto[8][FACTOR] = 5;
    this->Goto[8][FUNCTION_REF] = 9;

    // Transitions from state 10
    this->Goto[10][FACTOR] = 17;
    this->Goto[10][FUNCTION_REF] = 9;

        // Transitions from state 12
    this->Goto[12][SIMPLE_EXPR] = 19;
    this->Goto[12][TERM] = 3;
    this->Goto[12][FACTOR] = 5;
    this->Goto[12][FUNCTION_REF] = 9;

        // Transitions from state 13
    this->Goto[13][TERM] = 20;
    this->Goto[13][FACTOR] = 5;
    this->Goto[13][FUNCTION_REF] = 9;

        // Transitions from state 14
    this->Goto[14][FACTOR] = 21;
    this->Goto[14][FUNCTION_REF] = 9;

        // Transitions from state 18
    this->Goto[18][EXPR] = 23;
    this->Goto[18][SIMPLE_EXPR] = 2;
    this->Goto[18][TERM] = 3;
    this->Goto[18][FACTOR] = 5;
    this->Goto[18][FUNCTION_REF] = 9;
}

