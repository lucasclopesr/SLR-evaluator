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
      // Gerar os tokens de acordo com a gramática
      // Chamar a função do analisador sintático passando como parâmetro o vetor de tokens
      // Obter o resultado (válido ou não) e avaliar a expressão
    }


    // std::cout << "Expressão: " << input_string << std::endl;
  }

  return 0;
}

