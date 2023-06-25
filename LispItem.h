#pragma once

#include <list>
#include <string>

enum Type {ATOM, STRING, NUMBER, QUOTED_LIST, BRACKET_EXPR, NIL};

struct LispItem{ // tree element
    LispItem(): m_type(NIL){}
    LispItem(Type type, std::string strValue):m_type(type), stringValue(strValue){}

    Type m_type;
    std::string stringValue;
    int numberValue;
    std::list<LispItem> list;
};
