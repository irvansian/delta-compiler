#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <regex>
#include "token.h"

class Lexer {
public:
    std::vector<Token> tokenize(const std::vector<std::string>& lines);

private:
    Token classify(const std::string& token) const;
};

#endif
