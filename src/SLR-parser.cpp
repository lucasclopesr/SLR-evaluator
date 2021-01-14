#include <SLR-parser.hpp>

#define DEBBUGER false

SLR_Parser::SLR_Parser(){
    this->state_stack.push_back(ENTRY_STATE);
    this->table = new SLR_Table();
    // this->table->printAction();
    // this->table->printGoto();
}

bool SLR_Parser::parse(std::vector<int> expression){
    char type;
    int cur_state, new_state, symbol;

    int position = 0;
    symbol = expression[position];
    expression.push_back(EOE);

    bool is_valid = true;
    bool parsing = true;
    
    while(parsing){
        cur_state = this->state_stack.back();
        if (DEBBUGER) {
            std::cout << cur_state << "," << symbol << ": ";
        }
        std::tuple<char, int> action = 
            this->table->get_action(cur_state, symbol);

        type = std::get<0>(action); //Type of action to be executed
        new_state = std::get<1>(action); //State or rule

        if (DEBBUGER) {
            std::cout << type << "-" << new_state << std::endl;
        }

        if( type == 's'){ //Shift
            this->state_stack.push_back(new_state);
            this->symbol_stack.push_back(symbol);
            position++; 
            symbol = expression[position];

        } else if( type == 'r'){ //Reduce
            this->reduce(new_state);
            new_state = this->table->get_go_to(this->state_stack.back(),
                this->symbol_stack.back());
            if(new_state == GOTO_ERROR){
                is_valid = false;
                parsing = false;
            }
            this->state_stack.push_back(new_state);

        } else if(type == ACTION_ERROR){

            is_valid = false;
            parsing = false; 

        } else if(type == ACTION_ACC){
            parsing = false; 
        }else{
            is_valid = false;
            parsing = false; 
        }        
    }
    this->state_stack.pop_back();
    this->symbol_stack.pop_back();
    return is_valid;
}

bool SLR_Parser::reduce(int rule){
    int new_symbol, remove_n;

    switch (rule)
    {
    case 0:
        remove_n = 1;
        new_symbol = EXPR_EXP;
        break;

    case 1:
        remove_n = 1;
        new_symbol = EXPR;
        break;

    case 2:
        remove_n = 3;
        new_symbol = EXPR;
        break;

    case 3:
        remove_n = 1;
        new_symbol = SIMPLE_EXPR;
        break;

    case 4:
        remove_n = 2;
        new_symbol = SIMPLE_EXPR;
        break;
    
    case 5:
        remove_n = 3;
        new_symbol = SIMPLE_EXPR;
        break;
    
    case 6:
        remove_n = 1;
        new_symbol = TERM;
        break;

    case 7:
        remove_n = 3;
        new_symbol = TERM;
        break;

    case 8:
        remove_n = 1;
        new_symbol = FACTOR;
        break;
    
    case 9:
        remove_n = 1;
        new_symbol = FACTOR;
        break;

    case 10:
        remove_n = 3;
        new_symbol = FACTOR;
        break;

    case 11:
        remove_n = 1;
        new_symbol = FACTOR;
        break;


    case 12:
        remove_n = 2;
        new_symbol = FACTOR;
        break;


    case 13:
        remove_n = 1;
        new_symbol = FUNCTION_REF;
        break;


    case 14:
        remove_n = 4;
        new_symbol = FUNCTION_REF;
        break;

    default:
        return false;
    }

    std::cout << "Reduce:" << remove_n << ", " << new_symbol << std::endl;

    for(int i = 0; i < remove_n; i++){
        this->state_stack.pop_back();
        this->symbol_stack.pop_back();
    }
    this->symbol_stack.push_back(new_symbol);
    return true;
}
