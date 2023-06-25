#pragma once

#include "LispItem.h"
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include "builtinfuncmap.h"
#include "variablemap.h"

class Executor // выполняет дерево
{

private:
    static Executor* instance;

    // Private constructor to prevent instantiation
    Executor() {}

public:
    // map of variables and map of functions. If meet "funcdef" - map function body to atom
    BuiltInFuncMap m_builtInFuncMap;
    VariableMap m_variableMap;

    static Executor* getInstance();

    LispItem execute(LispItem item);
};

// defunc
// +
// setval
