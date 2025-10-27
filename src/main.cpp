#include <iostream>
#include <fstream>
#include "tokenizer/Tokenizer.h"
#include "utils/ReadFile.h"
#include "parser/Parser.h"


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    const std::fstream FILE = std::fstream(argv[1], std::ios::in);

    Tokenizer tokenizer;
    Parser parser;

    std::vector<Token> res = read_lines_tokenize(FILE, tokenizer);
    Program res2 = parser.identify_tokens(res);

    res2.print();

    return 0;
}
