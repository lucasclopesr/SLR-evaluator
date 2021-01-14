# Analisador Sintático
## Trabalho prático 2 ~ Compiladores
### UFMG DCC 2020/2. 
#### Por: Lucas Caetano Lopes Rodriguês, Lucas Starling De Paula Salles.
##### Prof: Mariza Bigonha.

# Introdução.

A tarefa proposta foi a implementação de um analisador sintático de expressoões matáticas para um conjunto de convenções lexicas e uma gramática definidos. A sintaxe contava com operadores logicos, de adição, multiplicação, parêntesis, sinais, constantes, variavéis e funções. O objetivo era gerar um codigo interativo, capaz de receber do usuario uma expressão, ou lista de expressões, para avaliação. O programa deve pedir para o usuario inserir o valor para variaveis, no momento de sua avaliação, caso existam. Por fim o avaliador deve resolver as expressões, em ordem entrada caso sua sintaxe esteja correta, e informar o resultado para o usuario. Uma expressão com sintaxe invalida deve exibir um erro e interromper a execução de programa, assim que o erro for verificado.

O primeiro passo desenvolver o analisador foi o tratamento da gramatica. Esse processo foi feito manualmente, e para tal foi nescessario entende-la. Percebemos que a definição para os sinais da gramatica existiam como uma convenção léxica além de uma regra da gramática, por isso escolhemos trata-los como simbulos lexicos, ou seja sinais foram usados como um simbulo terminal. Tendo isso definido seguimos para a expansão da gramática seguida pelo calculo do fechamento da mesma.

### A Gramática: 
 G' := expr_list
 expr_list := expr_list , expr
 expr_list := expr
 expr := simple_expr
 expr := simple_expr RELOP simple_expr
 simple_expr := term
 simple_expr := sign term
 simple_expr := simple_expr ADDOP term
 term := factor
 term := term MULOP factor
 factor := identifier
 factor := constant
 factor := ( expr )
 factor := function_ref
 factor := NOT factor
 function_ref := func_identifier
 function_ref := func_identifier ( expr_list )

 ### Closure:

- Closure1.png
- Closure2.png
- Closure3.png
- Closure4.png
- Closure5.png

---

# Desenvolvimento

## Modelo
Para desenvolver o projeto com o funcionamento correto tomamos como nescessaria a implementção não apenas do analisador sintático mas também de um léxico. O nanalisador léxico é responsável pela tokenização da entrada do usuario e o encaminhamento dos tokens gerados para a analise sintática.

O projeto deveria ser desenvolvido em Java ou c++. Nossa escolha foi pelo uso do c++, além de ser uma linguagem mais familiar para o grupo, consideramos uma linguagem mais bem otimizada e que atualmente é mais usada para o desenvolvimento de compiladores. 

Essa escolha atrasou um pouco o desenvolvimento, visto que havia sido disponibilizado um exemplo compreensivo em Java. Contudo nos aproveitamos de orientação à objetos e outras praticas de programação o que possibilitou a finalização do programa.
 

## LEXICO

    blaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

## Analisador Sintático

Análise sintatica de gramaticas SLR é feita usando a tecnica de `shift reduce` e pode ser entendida como uma maquina de estados, sua função de transição representa as possiveis transformações descritas pela grmática. Essa função transforma o estado atual em um proximo determinado pelo simbulo mais recente vindo de uma pilha que os armazena em ordem de entrada. Essas transições são definidas pela existencia de apenas um estado final, representando a aceitação sintatica da expressão avaliada, e um grande conjunto de casos onde a função não consegue alterar o estado, erros que interrompem o programa.

O algotitmo de analise foi implementado conforme os exemplos providos:

ALGOTIMO FOTO

Assim sendo a implementção contou com uma pilha de estado, uma pilha de simbulos, além daquela de entrada, e duas tabelas, Action e Goto. Essas tabelas foram modeladas como uma classe:
`    class SLR_Table {
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
};`

SNIPAR ESSE CODIGO DIREITO PLMD

Essas tabelas foram preenchidas usando o conjuto de fechamento de forma a compor de forma correta a tabela SLR para a gramatica.


TABELAO

Visualização das tabelas no codigo:

- Grammar1.png
- Grammar2.png

Esse objeto, `SLR_Table`, conta com os métodos responsaveis pela codificação e decodificação das ações esperadas para cada transição de estados valida, `composeAction()` e `get_action()` respectivamente. Ambas recebem o estado atual e simbulo atual como entrada. A notação usada armazenou shifts para um estado x como `s-x` e reduces usando a regra gramatical g como `r-g`. Além disso, o método `get_go_to()` também recebe o estado atual e o simbulo de entrada e retorna o estado o proximo estado da máquina. Por fim `printAction()` e `printGoto()` imprimem as respectivas tabelas, seus resultados podem ser observados acima.

O algoritmo de analise sintatica foi implementato também com o auxilio de uma classe:


class SLR_Parser {
    SLR_Table *table;
    std::vector<int> state_stack;
    std::vector<int> symbol_stack;
    public:
        SLR_Parser();
        bool parse(std::vector<int>);
    private:
        bool reduce(int); 
        void parse_action(std::string);
        void clean_parser();
}

SNIPPINGGGGGGGGGGGGGGGGGGG

Um objeto `SLR_Parser` conta com uma tabela `SLR_Table`, uma pilha de estados `state_stack` e uma pilha de simbulos percorridos `symbol_stack`. O método `clean_parser()` esvazia essas pilhas e `reduce()` é um auxiliar que recebe o numero da regra gramatical e realiza a redução corretamente. Por fim, `parse()` implementa o algoritmo mencionado, seu retorno indica se a expressão estava correta.


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
    this->clean_parser();
    return is_valid;
}

---

# Opreação

- Compilação: Feita atravéz de linha de comando. No diretorio do projeto basta executar `make` no terminal, será gerado no mesmo local um executével: `analisador`. O comando `make clean` também foi implementado para removel os objetos e o executavel.

FOTA

- Execução: Também por linha de comando, no diretorio executar `./analisador`.

FOTA

- Uso: O terminal que roda o programa espera uma expressão do usuario, se houverem variaveis seus valores serão pedidos ao usuario quando forem avaliados. Se a expressão estiver correta o resultado, ou resultados, são expostos na tela e o usuario poderá realizar o input novamente. Caso contário o programa exibirá uma mensaagem de erro e terminará sua execução.

FOTA

---

# Testes

Seguem evidências de diversos casos de execução geradas pelo programa:

V
A
R
I
A
S
F
O
T
A

