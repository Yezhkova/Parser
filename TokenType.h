#pragma once

enum class TokenType {
    OPEN_BRACKET,  // 0
    CLOSE_BRACKET, // 1
    SPACE,         // 2
    QUOTE,         // 3
//    DOUBLE_QUOTE,  // 4
    STRING,        // 4
    ATOM,          // 5
    SKIP,          // 6
    END            // 7
};
