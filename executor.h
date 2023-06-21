#pragma once

//    std::map<std::string, std::function< LispItem(const LispItem& l) > builtInFunctionMap;

//class Executor // выполняет дерево
//{
//    // map of variables and map of functions. If meet "funcdef" - map function body to atom
//    std::map<std::string, LispItem> variableMap;
//    std::map<std::string, LispItem> functionMap;

//    LispItem execute(LispItem item)
//    {
//        if(item.m_type == LispItem::ATOM){
//            auto it = variableMap.find(item.stringValue);
//            if(it == variableMap.end())
//            {
//                return LispItem{LispItem::NIL};
//            }
//            return it->second;
//        }

//        if(item.m_type == LispItem::BRACKET_EXPR){
//            auto firstElement = item.list.begin();
//            if(firstElement is built in)
//            {
//                pass the whole tail
//            }
//            auto it = functionMap.find(item.stringValue);
//            if(it == functionMap.end())
//            {
//                std::cerr<< "Error! You try to execute an undefined function " << item.stringValue << '\n';
//                exit(-1);
//            }
//            return it->second;
//        }

//        if(item.m_type == LispItem::STRING){
//            return item;
//        }

//        if(item.m_type == LispItem::NUMBER){
//            return item;
//        }

//        if(item.m_type == LispItem::QUOTED_LIST){
//            return execute(item);
//        }

//    }
//};

// defunc
// +
// setval
