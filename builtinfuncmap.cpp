#include "builtinfuncmap.h"
#include "executor.h"

BuiltInFuncMap::BuiltInFuncMap()
{
    m_functionMap["+"] = [](const LispItem& item) // (+ 5 6 8 9)
    {
        auto it = item.list.begin();
        it++;
        LispItem result(Type::STRING, std::string{});
        result.m_type = Type::STRING;
        for(; it !=item.list.end(); ++it)
        {
            result.stringValue += it->stringValue;
        }
        return result;
    };

    m_functionMap["setval"] = [](const LispItem& item) // (setval a "yu")
    {
        auto varName = ++item.list.begin();
        auto varValue = item.list.rbegin();
        //VariableMap varMap;
        Executor::getInstance()->m_variableMap.m_variableMap[varName->stringValue]
            = LispItem(Type::STRING, varValue->stringValue);
        return item;// кого возвращаем?
    };

    m_functionMap["defunc"] = [](const LispItem& item)
    {
        return item;
    };

};
