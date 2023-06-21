#pragma once

#include "LispItem.h"
#include <string>
#include <map>

class VariableMap
{
    std::map<std::string, LispItem> m_variableMap;

public:

    VariableMap();
};

