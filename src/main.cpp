#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "lexer.h"

int main() {
    std::string text;
    std::ifstream MainFile("main.del");
    std::vector<std::string> lines;

    while (std::getline(MainFile, text)) {
        if (text.empty()) continue;
        lines.push_back(text);
    }

    Lexer lexer;
    lexer.tokenize(lines);

    MainFile.close();

    return 0;
}
