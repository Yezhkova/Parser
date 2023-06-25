#include "executor.h"

Executor* Executor::getInstance()
{
    if (instance == nullptr) {
        instance = new Executor();
    }
    return instance;

}

LispItem Executor::execute(LispItem item)
{
    if(item.m_type == ATOM){
        auto it = m_variableMap.m_variableMap.find(item.stringValue);
        if(it == m_variableMap.m_variableMap.end())
        {
            return LispItem();
        }
        return it->second;
    }

    if(item.m_type == BRACKET_EXPR){
        auto firstElement = item.list.begin();
        //            if(firstElement is built in)
        //            {
        //                pass the whole tail
        //            }
        auto functionIt = m_builtInFuncMap.m_functionMap.find(item.stringValue);
        if(functionIt == m_builtInFuncMap.m_functionMap.end())
        {
            std::cerr<< "Error! You try to execute an undefined function " << item.stringValue << '\n';
            exit(-1);
        }
        return functionIt->second(item);
    }

    if(item.m_type == STRING){
        return item;
    }

    if(item.m_type == NUMBER){
        return item;
    }

    if(item.m_type == QUOTED_LIST){
        return execute(item);
    }
}
