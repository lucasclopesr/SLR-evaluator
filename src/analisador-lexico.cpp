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

float evaluate_factor(std::string factor){
  /* factor := identifier
   *        | constant
   *        | ( expr )
   *        | function_ref
   *        | NOT factor
   * if `identifier`, pedir o valor do identificador como entrada para o usuário
   */
  return 0.0;
};

float evaluate_term(std::string term){
  /* term := factor
   *        | term MULOP factor
   *
   * If MULOP -> call evaluate_term recursively on first term and evaluate_factor
   * on second term
   * else call evaluate_factor
   */
  return 0.0;
};


float evaluate_simple_expr(std::string simple_expr){
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
   return 0.0;
};

void tokenize(std::string expr){
  // std::regex RE_word("[a-zA-Z]*");
  // std::regex RE_number("[0-9]+");
  std::regex RE_id("[a-zA-Z]([a-zA-Z]|[0-9])*");
  std::regex RE_unsigned_int("[0-9][0-9]*");
  std::regex RE_sign("(\\+|-)?");
  std::regex RE_scale_factor("E(\\+|-)?[0-9][0-9]*");
  std::regex RE_unsigned_real("[0-9][0-9]*(\\.[0-9]+)?(E(\\+|-)?[0-9][0-9]*)?");
  std::regex RE_constant("(\\+|-)?([0-9][0-9]*(\\.[0-9]+)?(E(\\+|-)?[0-9][0-9]*)?|[0-9][0-9]*)");
  std::regex RE_relop("(<=|>=|<>|=|<|>)");
  std::regex RE_addop("(\\+|-|or)");
  std::regex RE_mulop("(\\*|/|div|mod|and)");
  std::regex RE_fun("(sin|cos|log)");

  std::sregex_iterator end;

  if (std::regex_search(expr, RE_relop)){
    // Caso expr := simple_expr RELOP simple_expr
    // avaliar simple_expr de cada lado e retornar o resultado do RELOP encontrado
    // @TODO: se RELOP size > 1, erro!
    std::cout << "expr := simple_expr RELOP simple_expr" << std::endl;
    std::sregex_iterator iter_relop(expr.begin(), expr.end(), RE_relop);
    while (iter_relop != end){
      for(unsigned i = 0; i < iter_relop->size() - 1; ++i)
      {
        if ((*iter_relop)[i].compare("") != 0){
          std::cout << "RELOP match: " << (*iter_relop)[i] << std::endl;
        }
      }
      ++iter_relop;
    }
  }

  // Caso expr := simple_expr
  // simple_expr := term
  //              | sign term
  //              | simple_expr ADDOP term

  if (std::regex_search(expr, RE_addop)){
    // Caso simple_expr := simple_expr ADDOP term
    // avaliar expressao e retornar o resultado
    std::cout << "expr := simple_expr ADDOP term" << std::endl;
    std::sregex_iterator iter_addop(expr.begin(), expr.end(), RE_addop);
    while (iter_addop != end){
      for(unsigned i = 0; i < iter_addop->size() - 1; ++i)
      {
        if ((*iter_addop)[i].compare("") != 0){
          std::cout << "ADDOP match: " << (*iter_addop)[i] << std::endl;
        }
      }
      ++iter_addop;
    }
  }

  if (std::regex_search(expr, RE_mulop)){
    // Caso term := term
    // avaliar expressao e retornar o resultado
    std::cout << "expr := simple_expr ADDOP term" << std::endl;
    std::sregex_iterator iter_addop(expr.begin(), expr.end(), RE_addop);
    while (iter_addop != end){
      for(unsigned i = 0; i < iter_addop->size() - 1; ++i)
      {
        if ((*iter_addop)[i].compare("") != 0){
          std::cout << "ADDOP match: " << (*iter_addop)[i] << std::endl;
        }
      }
      ++iter_addop;
    }
  }
 
  if (std::regex_search(expr, RE_addop)){
    // Caso simple_expr := term
    // avaliar expressao e retornar o resultado
    std::cout << "expr := simple_expr ADDOP term" << std::endl;
    std::sregex_iterator iter_addop(expr.begin(), expr.end(), RE_addop);
    while (iter_addop != end){
      for(unsigned i = 0; i < iter_addop->size() - 1; ++i)
      {
        if ((*iter_addop)[i].compare("") != 0){
          std::cout << "ADDOP match: " << (*iter_addop)[i] << std::endl;
        }
      }
      ++iter_addop;
    }
  }
  // std::sregex_iterator iter_letter(expr.begin(), expr.end(), RE_word);
  // while (iter_letter != end){
  //   for(unsigned i = 0; i < iter_letter->size(); ++i)
  //   {
  //     if ((*iter_letter)[i].compare("") != 0){
  //       std::cout << "Letter match: " << (*iter_letter)[i] << std::endl;
  //     }
  //   }
  //   ++iter_letter;
  // }

  // std::sregex_iterator iter_num(expr.begin(), expr.end(), RE_number);
  // while (iter_num != end){
  //   for(unsigned i = 0; i < iter_num->size(); ++i)
  //   {
  //     if ((*iter_num)[i].compare("") != 0){
  //       std::cout << "Number match: " << (*iter_num)[i] << std::endl;
  //     }
  //   }
  //   ++iter_num;
  // }

  // std::sregex_iterator iter_id(expr.begin(), expr.end(), RE_id);
  // while (iter_id != end){
  //   for(unsigned i = 0; i < iter_id->size(); ++i)
  //   {
  //     if ((*iter_id)[i].compare("") != 0){
  //       std::cout << "Identifier match: " << (*iter_id)[i] << std::endl;
  //     }
  //   }
  //   ++iter_id;
  // }

  // std::sregex_iterator iter_uint(expr.begin(), expr.end(), RE_unsigned_int);
  // while (iter_uint != end){
  //   for(unsigned i = 0; i < iter_uint->size(); ++i)
  //   {
  //     if ((*iter_uint)[i].compare("") != 0){
  //       std::cout << "Unsigned int match: " << (*iter_uint)[i] << std::endl;
  //     }
  //   }
  //   ++iter_uint;
  // }

  // std::sregex_iterator iter_sign(expr.begin(), expr.end(), RE_sign);
  // while (iter_sign != end){
  //   for(unsigned i = 0; i < iter_sign->size(); ++i)
  //   {
  //     if ((*iter_sign)[i].compare("") != 0){
  //       std::cout << "Sign match: " << (*iter_sign)[i] << std::endl;
  //     }
  //   }
  //   ++iter_sign;
  // }

  // std::sregex_iterator iter_sf(expr.begin(), expr.end(), RE_scale_factor);
  // while (iter_sf != end){
  //   for(unsigned i = 0; i < iter_sf->size(); ++i)
  //   {
  //     if ((*iter_sf)[i].compare("") != 0){
  //       std::cout << "Scale factor match: " << (*iter_sf)[i] << std::endl;
  //     }
  //   }
  //   ++iter_sf;
  // }

  // std::sregex_iterator iter_ufloat(expr.begin(), expr.end(), RE_unsigned_real);
  // while (iter_ufloat != end){
  //   for(unsigned i = 0; i < iter_ufloat->size(); ++i)
  //   {
  //     if ((*iter_ufloat)[i].compare("") != 0){
  //       std::cout << "Unsigned real match: " << (*iter_ufloat)[i] << std::endl;
  //     }
  //   }
  //   ++iter_ufloat;
  // }

  // std::sregex_iterator iter_constant(expr.begin(), expr.end(), RE_constant);
  // while (iter_constant != end){
  //   for(unsigned i = 0; i < iter_constant->size(); ++i)
  //   {
  //     if ((*iter_constant)[i].compare("") != 0){
  //       std::cout << "Constant match: " << (*iter_constant)[i] << std::endl;
  //     }
  //   }
  //   ++iter_constant;
  // }

};

int main(){
  /* Este é um programa interativo, executado pela CLI.
   * Cada input do usuário contém uma ou mais expressões que são entradas para
   * o analisador léxico. */

  std::string input_string = "";
  std::string expression = "";
  std::vector <std::string> expressions;


  while (input_string.compare("quit") != 0){
    // Recebe o input inteiro contendo uma ou mais expressões a serem avaliadas
    std::cout << "Entre com a expressão a ser avaliada: ";
    std::cin >> input_string;

    // Divide o input em expressões separadas por vírgula
    expressions = split(input_string);

    // Itera sobre cada expressão gerando os tokens
    for (auto & expr : expressions){
      std::cout << "Expr: " << expr << std::endl;

      tokenize(expr);
      // Gerar os tokens de acordo com a gramática
      // Chamar a função do analisador sintático passando como parâmetro o vetor de tokens
      // Obter o resultado (válido ou não) e avaliar a expressão
    }


    // std::cout << "Expressão: " << input_string << std::endl;
  }

  return 0;
}

