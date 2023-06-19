#include "LispItem.h"
#include "Token.h"
#include <deque>

class Scanner // из вектора токенов - лисп дерево
{
public:
    // add print function
    LispItem root;
    void scan(std::deque<Token> tokenList){
        for(auto& token: tokenList)
        {
            if(token.type == TokenType::OPEN_BRACKET)
            {
                // list starts
            }
            //            else..
        }
    }

};
