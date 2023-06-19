#pragma once

#include <list>
#include <string>

struct LispItem{ // tree element
    enum Type {ATOM, STRING, NUMBER, QUOTED_LIST, BRACKET_EXPR, NIL};
    Type m_type;
    std::string stringValue;
    int numberValue;
    std::list<LispItem> list;
};
