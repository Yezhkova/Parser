#pragma once
#include <functional>
#include <map>
#include <string>
#include "LispItem.h"

class BuiltInFuncMap
{
    std::map<std::string, std::function<LispItem(const LispItem&)>> m_functionMap;

public:
    BuiltInFuncMap();
};

