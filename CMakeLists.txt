cmake_minimum_required(VERSION 3.5)

project(Parser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE      main.cpp
    parser.h    parser.cpp
    mylists.h   mylists.cpp
    scanner.h   scanner.cpp
    executor.h  executor.cpp
    builtinfuncmap.h builtinfuncmap.cpp
    variablemap.h variablemap.cpp
    Token.h
    TokenType.h
    LispItem.h
)

add_executable(Parser ${SOURCE})

install(TARGETS Parser
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
