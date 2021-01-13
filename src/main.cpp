#include <grammar-constants.hpp>

int main(){
    SLR_Table table;
    table.printAction();
    table.printGoto();
    return 0;
}