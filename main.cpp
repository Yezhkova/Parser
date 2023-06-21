#include "parser.h"
#include "scanner.h"
#include <iostream>

using namespace std;

int main() {
    std::string input;
    std::cout << "Enter an arithmetic expression: ";
    std::getline(std::cin, input);

    Parser parser(input);
    Scanner scanner;
    try {
        parser.parse();
        parser.print();
        scanner.scan(parser.getTokenList());
        scanner.print();
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}

