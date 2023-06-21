#pragma once
#include "Token.h"
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class Parser
{ // из исходного текста - список токенов

    std::string m_input;
    size_t m_position;
    std::deque<Token> m_tokenList;

    bool m_stringStarted = false; // inside " "
    int m_stringBeginPosition;

    bool m_atomStarted = false; // everything else (function, variable etc..)
    int m_atomBeginPosition;
    bool m_atomEnded = false;

    std::string m_parsedAtom;
    std::string m_parsedString;

public:
    Parser(const std::string &input)
        : m_input(input)
        , m_position(0)
    {}

    const std::deque<Token>& getTokenList() const
    {
        return m_tokenList;
    }

    TokenType getNextToken()
    {
        if (m_position >= m_input.size()) {
            if (m_atomStarted) {
                m_atomEnded = true;
            }

            return TokenType::END;
        }

        char currentChar = m_input[m_position];

        if (currentChar == '(') {
            m_position++;
            if (m_atomStarted) {
                m_atomEnded = true;
            }
            return TokenType::OPEN_BRACKET;
        }
        else if (currentChar == ')') {
            m_position++;
            if (m_atomStarted) {
                m_atomEnded = true;
            }
            return TokenType::CLOSE_BRACKET;
        }
        else if (currentChar == ' ') {
            m_position++;
            if (m_atomStarted) {
                m_atomEnded = true;
            }
            return TokenType::SPACE;
        }
        else if (currentChar == '"') {
            m_position++;

            if (!m_stringStarted && m_atomStarted) {
                m_atomEnded = true;
            }

            else if (m_stringStarted) {
                m_stringStarted = false;
                m_parsedString = std::string(m_input.begin() + m_stringBeginPosition,
                                             m_input.begin() + m_position - 1);
                return TokenType::STRING;
            }
            m_stringStarted = true;
            m_stringBeginPosition = m_position;
            return TokenType::SKIP;
        }
        else if (currentChar == '\'') {
            m_position++;
            if (m_atomStarted) {
                m_atomEnded = true;
            }

            return TokenType::QUOTE;
        }
        else if(m_stringStarted){
            m_position++;
            return TokenType::SKIP;
        }

        else {
            if (!m_atomStarted) {
                m_atomStarted = true;
                m_atomBeginPosition = m_position;
            }
            m_position++;
            return TokenType::SKIP;
        }


        throw std::runtime_error("Invalid token");
    }

    void parse()
    {
        TokenType currentTokenType;
        do {
            currentTokenType = getNextToken();

            if (m_atomStarted && m_atomEnded) {
                m_atomStarted = false;
                m_atomEnded = false;
                m_parsedAtom = std::string(m_input.begin() + m_atomBeginPosition,
                                           m_input.begin() + m_position - 1);
                m_tokenList.push_back(std::move(Token{TokenType::ATOM, m_parsedAtom}));
            }

            if (currentTokenType == TokenType::SKIP) {
                continue;
            }

            if (currentTokenType == TokenType::STRING) {
                m_tokenList.push_back(std::move(Token{TokenType::STRING, m_parsedString}));
                continue;
            }

            m_tokenList.push_back(std::move(Token{currentTokenType, {}}));
        } while (currentTokenType != TokenType::END);
    }

    void print()
    {
        for (auto &token : m_tokenList) {
            std::cout << int(token.type);
        }
        std::cout << '\n';
    }
};
