#include "LispItem.h"
#include "Token.h"
#include <deque>
#include <iostream>

class Scanner // из вектора токенов - лисп дерево
{
public:

    LispItem root; // почему это root, если это не элемент списка, а список в нем самом?

    void scan(std::deque<Token> tokenList){
        for (auto tokenIt = tokenList.begin(); tokenIt != tokenList.end(); ++tokenIt)
        {
            if(tokenIt->type == TokenType::END)
            {
                break;
            }
            auto item = scanR(tokenIt, tokenList.end());
            root.list.push_back(item);
            root.m_type = Type::BRACKET_EXPR;
        }
    }

    LispItem scanR(std::deque<Token>::iterator &tokenIt
               , std::deque<Token>::const_iterator endIt
               , bool isQuoted = false)
    {
        LispItem item; //

        for (; tokenIt != endIt; ++tokenIt) {
            if (tokenIt->type == TokenType::OPEN_BRACKET)
            {
                // list starts
                for(;;)
                {
                    ++tokenIt;
                    if(tokenIt == endIt)
                    {
                        std::cerr << "Error! No closing bracket matching";
                        exit(-1);
                    }
                    if(tokenIt->type == TokenType::CLOSE_BRACKET)
                    {
                        return item;
                    }
                    auto scannedItem = scanR(tokenIt, endIt);
                    item.list.push_back(scannedItem);
                    if(isQuoted)
                    {
                        item.m_type = Type::QUOTED_LIST;
                    }
                    else
                    {
                        item.m_type = Type::BRACKET_EXPR;
                    }

                }
            }
            else if(tokenIt->type == TokenType::CLOSE_BRACKET)
            {
                std::cerr << "Error! No opening bracket matching";
                exit(-1);
            }
            else if(tokenIt->type == TokenType::ATOM)
            {
                item.m_type = Type::ATOM;
                item.stringValue = tokenIt->value;
                return item;
            }
            else if(tokenIt->type == TokenType::STRING)
            {
                item.m_type = Type::STRING;
                item.stringValue = tokenIt->value;
                return item;
            }
            else if(tokenIt->type == TokenType::QUOTE)
            {
                ++tokenIt;
                return scanR(tokenIt, endIt, true);
            }
            else if(tokenIt->type == TokenType::END)
            {
                std::cerr<< "Error! Unexpected end";
                exit(-1);
            }
        }
        return item;
    }

    void print() const
    {
        if(root.m_type == Type::NIL)
        {
            std::cout << "NIL";
        }
        else
        {
            for(auto& item: root.list)
            {
                print(item);
            }
        }
    }

    void print(const LispItem& item) const
    {
        switch (item.m_type) {
        case Type::ATOM:
        case Type::STRING:
        case Type::NUMBER:
            std::cout << item.stringValue;
            break;


        case Type::QUOTED_LIST:
            std::cout << "'";

        case Type::BRACKET_EXPR:
            std::cout << "(";
            for(const auto& subItem: item.list)
            {
                print(subItem);
                std::cout << " ";
            }
            std::cout << ")";
            break;


        case Type::NIL:
            std::cout << "NIL";
            break;

        default:
            break;
        }
    }

};
