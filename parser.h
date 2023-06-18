#pragma once
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <vector>

enum class TokenType { // map -     NUMBER, SYMBOL separately
    NUMBER,
    PLUS,
    MINUS,
    OPENBRACKET,
    CLOSEBRACKET,
    SPACE,
    QUOTE,
    QUOTES,
    SYMBOL,
    END
};

struct Token {
    TokenType type;
    std::string value;
};

//Token makeToken(char currentChar)
//{
//if(find currentChar in TokenType map)
//    return Token(..., currentChar);
//}

class Parser {
public:
    Parser(const std::string& input) : input_(input), position_(0) {}

    Token getNextToken() {
        if (position_ >= input_.size()) {
            return { TokenType::END, "" };
        }

        char currentChar = input_[position_];
        if (isdigit(currentChar)) {
            std::stringstream numberStream;
            while (position_ < input_.size() && isdigit(input_[position_])) {
                numberStream << input_[position_];
                position_++;
            }
            return { TokenType::NUMBER, numberStream.str() };
        }
        else if (currentChar == '+') {
            position_++;
            return { TokenType::PLUS, "+" };
        }
        else if (currentChar == '-') {
            position_++;
            return { TokenType::MINUS, "-" };
        }
        else if (currentChar == '(') {
            position_++;
            return { TokenType::OPENBRACKET, "(" };
        }
        else if (currentChar == ')') {
            position_++;
            return { TokenType::CLOSEBRACKET, ")" };
        }
        else if (currentChar == ' ') {
            position_++;
            return { TokenType::SPACE, " " };
        }
        else if (currentChar == '"') {
            position_++;
            return { TokenType::QUOTES, "\"" };
        }
        else if (currentChar == '\'') {
            position_++;
            return { TokenType::QUOTE, "\'" };
        }
        else {
            position_++;
            return { TokenType::SYMBOL, std::string(1, currentChar) };
        }

        throw std::runtime_error("Invalid token");
    }

    void parse() {
        Token currentToken;
        do{
            currentToken = getNextToken();
            tokenList_.push_back(std::move(currentToken));
        }
        while(currentToken.type != TokenType::END);
    }

    void print()
    {
        for(auto& token: tokenList_){
            std::cout << token.value;
        }
        std::cout << '\n';
    }

private:
    std::string input_;
    size_t position_;
    std::list<Token> tokenList_;
};
