#include "parser.h"
#include <iostream>

using namespace std;

int main() {
    std::string input;
    std::cout << "Enter an arithmetic expression: ";
    std::getline(std::cin, input);

    Parser parser(input);
    try {
        parser.parse();
        parser.print();
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}

