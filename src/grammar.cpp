#include <grammar.hpp>

#if SIMPLE_GRAMMAR
std::string Grammar::terms[] = {"RELOP", "SIGN", "ADDOP", "MULOP",
 "IDENTIFIER", "CONSTANT", "OPEN_P", "CLOSE_P", "NOT", "FUNC_IDENTIFIER", "EOE"};

std::string Grammar::n_terms[] = {"EXPR_EXP", "EXPR",
 "SIMPLE_EXPR", "TERM", "FACTOR", "FUNCTION_REF"};
#else
std::string Grammar::terms[] = {"COMMA", "RELOP", "SIGN", "ADDOP", "MULOP",
 "IDENTIFIER", "CONSTANT", "OPEN_P", "CLOSE_P", "NOT", "FUNC_IDENTIFIER", "EOE"};

std::string Grammar::n_terms[] = {"EXPR_EXP", "EXPR_LIST", "EXPR",
 "SIMPLE_EXPR", "TERM", "FACTOR", "FUNCTION_REF"};
#endif

Grammar *Grammar::_Grammar;
std::vector<Token> Grammar::_tokens;

Grammar*  Grammar::getGrammar(){
    if (!Grammar::_Grammar) {
    Grammar::_Grammar = new Grammar;
    Grammar::loadTokens();
  }

  return Grammar::_Grammar;
}


void Grammar::loadTokens(){
    for(int i = 0; i < TERMINALS; i++){

        Grammar::_tokens.push_back(Token(i, Grammar::terms[i] ));

    }

    for(int i = 0; i < NON_TERMINALS; i++){
        Grammar::_tokens.push_back(Token(i, Grammar::n_terms[i]));

    }
}

std::string Grammar::get(int id){
    for(auto & token : this->_tokens){
        if(token.getId() == id){
            return token.getName();
        }
    }
    return "Token not found";
}

int Grammar::get(std::string name){
    for(auto & token : this->_tokens){
        if(token.getName() == name){
            return token.getId();
        }
    }
    return -1;
}

void Grammar::print(){
    for(auto & toker : this->_tokens){
        std::cout << toker.getName() << " " << toker.getId() << std::endl;
    }
}


Token::Token(int _id, std::string _name){
    this->id = _id;
    this->name = _name;
}

int Token::getId(){
    return this->id;
}

std::string Token::getName(){
    return this->name;
}
