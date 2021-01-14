/* O analisador léxico deve receber uma expressão e retornar um vetor de pares
 * no formato (token, ID). Em seguida, ele deve enviar esses pares ao analisador
 * sintático, que irá conferir se os tokens estão sintaticamente corretos.
 * 
 * As expressões podem ter, por exemplo, os formatos:
 *  - -3.2e-1
 *  - 1 + 4 - 8367.7 + beta, 2 + 357, 99e-10
 */

#include <iostream>
#include <string>
#include <vector>
#include <regex>

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

// Símbolos terminais:
// std::regex RE_word("[a-zA-Z]*");
// std::regex RE_number("[0-9]+");
// std::regex RE_unsigned_int("[0-9][0-9]*");
// std::regex RE_sign("(\\+|-)?");
// std::regex RE_scale_factor("E(\\+|-)?[0-9][0-9]*");
// std::regex RE_unsigned_real("[0-9][0-9]*(\\.[0-9]+)?(E(\\+|-)?[0-9][0-9]*)?");
std::regex RE_id("[a-zA-Z]([a-zA-Z]|[0-9])*");
std::regex RE_constant("(\\+|-)?([0-9][0-9]*(\\.[0-9]+)?(E(\\+|-)?[0-9][0-9]*)?|[0-9][0-9]*)");
std::regex RE_relop("(<=|>=|<>|=|<|>)(?![^(]*\\))(?!\\([^)]*)");
std::regex RE_addop("\\b(\\+|-|or)(?![^(]*\\))");
std::regex RE_mulop("(\\*|/|div|mod|and)(?![^(]*\\))");
std::regex RE_fun("(sin|cos|log)");
std::regex RE_parenthesis("(\\(*\\))");
std::regex RE_not("NOT");
std::regex RE_sign("(\\+|-|or)");

std::vector <int> evaluate_expr(std::string expr);

std::vector <std::string> split(std::string s){
  /* Quebra uma string que contém expressões separadas por vírgual em
   * um vetor de strings contendo cada expressão
   */

  std::vector <std::string> expressions;
  std::string expr;
  std::string delimiter = ",";
  size_t pos = 0;

  while ((pos = s.find(delimiter)) != std::string::npos){
    expr = s.substr(0, pos);
    expressions.push_back(expr);
    // std::cout << "Expression: " << exp << std::endl;
    s.erase(0, pos + delimiter.length());
  }

  expressions.push_back(s);
  // std::cout << "Final string: " << s << std::endl;

  return expressions;
};

std::vector <int> evaluate_factor(std::string factor){
  /* factor := identifier
   *        | constant
   *        | ( expr )
   *        | function_ref
   *        | NOT factor
   * if `identifier`, pedir o valor do identificador como entrada para o usuário
   */
  std::cout << "evaluate_factor: " << factor << std::endl;
  std::smatch op;
  std::vector <int> int_expr; // The final expression vector (see code list in #DEFINES section)

  if (std::regex_search(factor, op, RE_fun)){

    std::cout << "FUNCT EXPR match: " << op[0] << std::endl;

    size_t open_par_pos = factor.find("(");
    size_t close_par_pos = factor.find(")");
    size_t function_pos = factor.find(op[0]);
    factor.erase(function_pos, 3);

    std::string expr_in_parenthesis = factor.substr(open_par_pos+1, close_par_pos-open_par_pos-1);

    std::cout << "Function expr: " << factor << std::endl;
    std::vector <int> factor_code = evaluate_expr(factor);

    int_expr.push_back(FUNC_IDENTIFIER);
    int_expr.push_back(OPEN_P);
    int_expr.insert(int_expr.end(), factor_code.begin(), factor_code.end());
    int_expr.push_back(CLOSE_P);

    return int_expr;
  } else if (std::regex_search(factor, op, RE_parenthesis)){

    std::cout << "PARENTHESIS  match" << std::endl;

    size_t open_par_pos = factor.find("(");
    size_t close_par_pos = factor.find(")");

    // std::cout << "Parenthesis expr: " << expr_in_parenthesis << std::endl;
    std::cout << "PARENTHESIS open: " << open_par_pos << std::endl;
    std::cout << "PARENTHESIS close: " << close_par_pos << std::endl;

    std::string expr_in_parenthesis = factor.substr(open_par_pos+1, close_par_pos-open_par_pos-1);

    std::cout << "Parenthesis expr: " << expr_in_parenthesis << std::endl;
    std::vector <int> expr_code = evaluate_expr(expr_in_parenthesis);

    int_expr.push_back(OPEN_P);
    int_expr.insert(int_expr.end(), expr_code.begin(), expr_code.end());
    int_expr.push_back(CLOSE_P);

    return int_expr;
  }/* else if (std::regex_search(factor, op, RE_not)){
    std::cout << "NOT  match: " << op[0] << std::endl;
    return 0.0;
  }*/ else if (std::regex_search(factor, op, RE_id)){
    std::cout << "IDENTIFIER match: " << op[0] << std::endl;
    int_expr.push_back(IDENTIFIER);

    return int_expr;
  } else if (std::regex_search(factor, op, RE_constant)){
    std::cout << "CONSTANT match: " << op[0] << std::endl;
    int_expr.push_back(CONSTANT);

    return int_expr;
  } else {
    std::cout << "ERRO! SIMBOLO TERMINAL NAO RECONHECIDO" << std::endl;
    int_expr.push_back(RELOP);
  }
  return int_expr;
};

float evaluate_mulop(float factor1, float factor2, std::string mulop){
  /*
   * Calculate MULOP relation
  */

  std::cout << "Evaluate mulop!" << std::endl;
  return 0.0;
};

std::vector <int> evaluate_term(std::string term){
  /* term := factor
   *        | term MULOP factor
   *
   * If MULOP -> call evaluate_term recursively on first term and evaluate_factor
   * on second term
   * else call evaluate_factor
   */

  std::vector <int> int_expr; // The final expression vector (see code list in #DEFINES section)

  std::cout << "evaluate_term: " << term << std::endl;
  std::smatch op;
  if (std::regex_search(term, op, RE_mulop)){
    // Caso term := term MULOP factor
    std::cout << "MULOP match: " << op[1] << std::endl;
    std::cout << "MULOP length: " << op[1].length() << std::endl;
    
    size_t mulop_pos = term.find(op[1]);
    // simple expression before MULOP
    std::string term1 = term.substr(0,mulop_pos);
    
    // simple expression after MULOP
    std::string factor = term.substr(mulop_pos+op[1].length(),term.length());


    std::vector <int> term_result = evaluate_term(term1);
    std::vector <int> factor_result = evaluate_factor(factor);
    
    int_expr.insert(int_expr.end(), term_result.begin(), term_result.end());
    int_expr.push_back(MULOP);
    int_expr.insert(int_expr.end(), factor_result.begin(), factor_result.end());

    //float result = evaluate_mulop(term_result, factor_result, op[1]);
    //return result;
  } else {
    // simple_expr := term
    std::vector <int> term_result = evaluate_factor(term);
    int_expr.insert(int_expr.end(), term_result.begin(), term_result.end());
  }
 
 return int_expr;
};


float evaluate_addop(float term1, float term2, std::string addop){
  /*
   * Calculate ADDOP relation
  */

  std::cout << "Evaluate addop!" << std::endl;
  return 0.0;
};

std::vector <int>evaluate_simple_expr(std::string simple_expr){
  /* simple_expr := term
   *              | sign term
   *              | simple_expr ADDOP term
   *
   * If ADDOP -> call evaluate_simple_expr recursively on first term and evaluate_term
   * on second term.
   *
   * else if SIGN -> call evaluate_term with sign?
   * else call evaluate_term with no sign (positive as default?)
   *
   */
  // Caso expr := simple_expr
  // simple_expr := term
  //              | sign term
  //              | simple_expr ADDOP term

  std::cout << "evaluate_simple_expr: " << simple_expr << std::endl;

  std::smatch op;
  std::vector <int> int_expr; // The final expression vector (see code list in #DEFINES section)

  if (std::regex_search(simple_expr, op, RE_addop)){
    std::cout << "ADDOP match: " << op[1] << std::endl;
    
    size_t addop_pos = simple_expr.find(op[1]);
    // simple expression before ADDOP
    std::string se1 = simple_expr.substr(0,addop_pos);
    std::cout << "Termo 1: " << se1 << std::endl;

    // simple expression after ADDOP
    std::string term = simple_expr.substr(addop_pos+1,simple_expr.length());
    std::cout << "Termo 2: " << term << std::endl;


    std::vector <int> se1_result = evaluate_simple_expr(se1);
    std::vector <int> term_result = evaluate_term(term);
    int_expr.insert(int_expr.end(), se1_result.begin(), se1_result.end());
    int_expr.push_back(ADDOP);
    int_expr.insert(int_expr.end(), term_result.begin(), term_result.end());
    
    //float result = evaluate_addop(se1_result, term_result, op[1]);
  } else {
    // simple_expr := term
    std::vector <int> se_result = evaluate_term(simple_expr);

    int_expr.insert(int_expr.end(), se_result.begin(), se_result.end());
  }

  return int_expr;
};

float evaluate_relop(float se1, float se2, std::string relop){
  /*
   * Calculate RELOP relation
  */
  std::cout << "Evaluate relop!" << std::endl;
  return 0.0;
};

std::vector <int> evaluate_expr(std::string expr){

  std::smatch op;
  std::vector <int> int_expr; // The final expression vector (see code list in #DEFINES section)

  if (std::regex_search(expr, op, RE_relop)){
    std::cout << "RELOP match: " << op[1] << std::endl;

    size_t relop_pos = expr.find(op[1]);
    // simple expression before RELOP
    std::string se1 = expr.substr(0,relop_pos);
    std::cout << "se1: " << se1 << std::endl;
    
    // simple expression after RELOP
    std::string se2 = expr.substr(relop_pos+1,expr.length());
    std::cout << "se2: " << se2 << std::endl;

    std::vector <int> se1_result = evaluate_simple_expr(se1);
    std::vector <int> se2_result = evaluate_simple_expr(se2);
    int_expr.insert(int_expr.end(), se1_result.begin(), se1_result.end());
    int_expr.push_back(RELOP);
    int_expr.insert(int_expr.end(), se2_result.begin(), se2_result.end());

    //bool result = evaluate_relop(se1_result, se2_result, op[1]);
    //return result;
  } else {
    std::cout << "SIMPLE EXPRESSION match: " << expr << std::endl;
    std::vector <int> se_result = evaluate_simple_expr(expr);
    int_expr.insert(int_expr.end(), se_result.begin(), se_result.end());
  }

  return int_expr;
};

int main(){
  /* Este é um programa interativo, executado pela CLI.
   * Cada input do usuário contém uma ou mais expressões que são entradas para
   * o analisador léxico. */

  try{

    std::string input_string = "";
    std::string expression = "";
    std::vector <std::string> expressions;


    while (input_string.compare("quit") != 0){
      // Recebe o input inteiro contendo uma ou mais expressões a serem avaliadas
      std::cout << "Entre com a expressão a ser avaliada: ";
      std::cin >> input_string;

      // Divide o input em expressões separadas por vírgula
      expressions = split(input_string);
      // @TODO: checar sintaxe de expr_list

      // Itera sobre cada expressão gerando os tokens
      for (auto & expr : expressions){
        std::cout << "Expr: " << expr << std::endl;

        std::vector <int> int_expr = evaluate_expr(expr);
        std::cout << std::endl;
        for (auto & code : int_expr){
          std::cout << code;
        }

        std::cout << std::endl;
        // Gerar os tokens de acordo com a gramática
        // Chamar a função do analisador sintático passando como parâmetro o vetor de tokens
        // Obter o resultado (válido ou não) e avaliar a expressão
      }


      // std::cout << "Expressão: " << input_string << std::endl;
    }

    return 0;

  } catch(std::exception& e){
    std::cout << "Expressão inválida" << std::endl;
  }

}



/*
seja a o primeiro símbolo de w$;
while(1) { // repita indefinidamente 
  seja S o estado no topo da pilha;
  if ( ACTION[S,a] = shift t ) {
    empilha t na pilha;
    seja a o próximo símbolo da entrada;
  } else if ( ACTION[S,a] = reduce A -> B ) {
    desempilha símbolos || da pilha;
    faça o estado t agora ser o topo da pilha;
    empilhe GOTO[t,A] na pilha;
    imprima a produção A -> B ;
  } else if ( ACTION[S,a] = accept ) pare; //
  else chame uma rotina de recuperação de erro;
}
*/
