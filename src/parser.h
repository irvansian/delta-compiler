#include <vector>
#include "token.h"

class Parser {
public:
    Parser(const std::vector<Token>& tokens);

private:
    const std::vector<Token>& tokens;
    size_t currentIndex;

    Token currentToken() const; // const doesn't modify member of the class
    void advance();

    void parseStatement() const;
    void parseExpression() const;
    void parseFactor() const;
    void parseTerm() const;
}