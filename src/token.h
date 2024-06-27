#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenType {
    //KEYWORDS
    IF, ELSE, WHILE, FOR, FROM, TO, RETURN, DEF, CLASS, IMPORT, BREAK,
    CONTINUE, TRUE,

    // variable names
    IDENTIFIER,

    //LITERALS
    STRING_LITERAL,
    DOUBLE_LITERAL,
    INTEGER_LITERAL,
    FALSE, NONE,

    //operators
    PLUS, MINUS, MULTIPLY, DIVIDE, MODULO, POWER, FLOOR_DIV,
    ASSIGN, PLUS_ASSIGN, MINUS_ASSIGN, MULTIPLY_ASSIGN, DIVIDE_ASSIGN, 
    MODULO_ASSIGN, POWER_ASSIGN, FLOOR_DIV_ASSIGN,
    EQUAL, NOT_EQUAL, GREATER, LESS, GREATER_EQUAL, LESS_EQUAL, AND, OR, NOT,
    BIT_AND, BIT_OR, BIT_XOR, BIT_NOT, LEFT_SHIFT, RIGHT_SHIFT,

    // mbuh
    COLON, DOT, WHITESPACE,

    // comments
    COMMENT
};

struct Token {
    TokenType type;
    std::string value;
};

#endif