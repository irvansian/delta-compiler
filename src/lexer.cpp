#include "lexer.h"

std::vector<Token> Lexer::tokenize(const std::vector<std::string>& lines) {
    std::vector<Token> tTokens;
    for (std::string line : lines) {
        std::cout << "The line is : " << line << std::endl;
        std::vector<std::string> tokens;
        std::string curString = "";
        bool inString = false;
        int countQuote = 0;

        for (char c : line) {
            if (c == '"') {
                countQuote++;
            }

            inString = (countQuote % 2 != 0) ? true : false;

            if (isspace(c) && !inString) {
                if (!curString.empty()) {
                    tokens.push_back(curString);
                    curString = "";
                    continue;
                }
            }

            if (c == '(') {
                tokens.push_back(curString);
                tokens.push_back("(");
                curString = "";
                continue
            }

            if (c == ')') {
                tokens.push_back(curString);
                tokens.push_back(")");
                curString = "";
                continue
            }

            if (c == ':') {
                tokens.push_back(curString);
                tokens.pop_back(":");
                curString = "";
                continue
            }
            curString += c;
        }
        if (!curString.empty()) tokens.push_back(curString);
        
        for (std::string token : tokens) {
            tTokens.push_back(classify(token));
        }
    }
    for (Token token : tTokens) {
        std::cout << "Token : " << token.value << ", type : " << token.type << std::endl;
    }
    return tTokens;
}

Token Lexer::classify(const std::string& token) const {
    // reserved keywords
    if (token == "jika") return {TokenType::IF, token};
    if (token == "untuk") return {TokenType::FOR, token};
    if (token == "dari") return {TokenType::FROM, token};
    if (token == "ke") return {TokenType::TO, token};
    if (token == "kembalikan") return {TokenType::RETURN, token};
    if (token == "fungsi") return {TokenType::DEF, token};
    if (token == "kerangka") return {TokenType::CLASS, token};
    if (token == "pakai") return {TokenType::IMPORT, token};
    if (token == "berhenti") return {TokenType::BREAK, token};
    if (token == "lanjut") return {TokenType::CONTINUE, token};
    if (token == "Benar") return {TokenType::TRUE, token};
    if (token == "Salah") return {TokenType::FALSE, token};

    // Case: identifier
    std::regex identifier_pattern(R"([a-zA-Z_][a-zA-Z0-9_]*)");
    if (std::regex_match(token, identifier_pattern)) {
        return {TokenType::IDENTIFIER, token};
    }

    // Case: integer literal
    std::regex integer_pattern(R"(\d+)");
    if (std::regex_match(token, integer_pattern)) {
        return {TokenType::INTEGER_LITERAL, token};
    }

    // string literal
    if (token[0] == '"' && token[token.length() - 1] == '"') return {TokenType::STRING_LITERAL, token};

    //operators
    if (token == "dan") return {TokenType::AND, token};
    if (token == "atau") return {TokenType::OR, token};
    if (token == "tidak") return {TokenType::NOT, token};
    if (token == "+") return {TokenType::PLUS, token};
    if (token == "-") return {TokenType::MINUS, token};
    if (token == "/") return {TokenType::DIVIDE, token};
    if (token == "*") return {TokenType::MULTIPLY, token};
    if (token == "=") return {TokenType::ASSIGN, token};
    if (token == "==") return {TokenType::EQUAL, token};
    if (token == "!=") return {TokenType::NOT_EQUAL, token};
    if (token == ">") return {TokenType::GREATER, token};
    if (token == "<") return {TokenType::LESS, token};
    if (token == ">=") return {TokenType::GREATER_EQUAL, token};
    if (token == "<=") return {TokenType::LESS_EQUAL, token};
    
    if (token == ":") return {TokenType::COLON, token};
    if (token == ".") return {TokenType::DOT, token};
    if (token == "(") return {TokenType::LP, token};
    if (token == ")") return {TokenType::RP, token};
}
