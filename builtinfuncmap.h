#pragma once
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include "LispItem.h"

class BuiltInFuncMap
{
public:
    std::map<std::string, std::function<LispItem(const LispItem&)>> m_functionMap;

    BuiltInFuncMap();


    // (defunc funcName (arg1 arg2) (+ arg1 arg2) (if condition (return 0) else (return 1)) )

};
