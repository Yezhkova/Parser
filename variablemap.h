#pragma once

#include "LispItem.h"
#include <string>
#include <map>

class VariableMap
{
public:
    std::map<std::string, LispItem> m_variableMap;
    VariableMap();
};

