#ifndef ARKA_TOKENIZER_H
#define ARKA_TOKENIZER_H

#include <string>
#include <vector>
#include <map>
#include <cstdint>


enum TokenTypes
{
    NumberLiteral,
    Identifier,
    Equal,
    Plus,
    Minus,
    Star,
    Slash,
    L_Paren,
    R_Paren,
    L_Bracket,
    R_Bracket,
    Semicol,
    Colon,
    Hashtag,
    Space,
    Endl,
    A_Slash,
    Tab,
    Underscore,
    Vertical_Bar,
    L_Angle_Bracket,
    R_Angle_Bracket,
    L_Square_Bracket,
    R_Square_Bracket,
    D_Quote,
    Quote,
    Dollar,
    Dot,
    Comma,
    UNDEFINED,
};

extern std::map<TokenTypes, std::string> TokenTypeNames;


struct Token
{
    TokenTypes token_type;
    std::string lexem;
};

void print_token(Token& tok);
void print_tab(uint8_t tab);

class Tokenizer
{
public:
    std::vector<Token> tokenize(std::string code);

private:
};

#endif //ARKA_TOKENIZER_H
