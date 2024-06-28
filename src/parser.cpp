#include "parser.h"

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), currentIndex(0) {}

Token Parser::currentToken() const {
    if (currentIndex < token.size()) {
        return tokens[currentIndex]
    }
    return {TokenType::EOF, ""}
}

void Parser::advance() {
    if (currentIndex < tokens.size()) currentIndex++;
}

void Parser::parseStatement() const {
    if (currentToken().type == TokenType::IDENTIFIER) {
        advance(); //consume IDENTIFIER
        if (currentToken().type == TokenType::ASSIGN) {
            advance(); //consume ASSIGN
            parseExpression(currentToken());
        }
    }
}

void Parser::parseExpression() const {
    parseTerm();
    while (currentToken().type == TokenType::PLUS || currentToken().type == TokenType::MINUS) {
        advance(); //consume PLUS or MINUS
        parseTerm(currentToken());
    }
}

void Parser::parseTerm() const {
    parseFactor();
    while (currentToken().type == TokenType::MULTIPLY || currentToken().type == TokenType::DIVIDE) {
        advance(); //consume MULTIPLY or DIVIDE
        parseFactor(currentToken());
    }
}

void Parser::parseFactor() const {
    if (currentToken().type == TokenType::INTEGER_LITERAL 
        || currentToken().type == TokenType::DOUBLE_LITERAL
        || currentToken().type == TokenType::IDENTIFIER) {
        advance(); //consume the number
    } else {
        if (currentToken().type == TokenType::LP) {
            advance();
        }

        parseExpression(currentToken());
        if (currentToken().type == TokenType::RP) {
            advance(); //consume RP
        }
    }
    
}