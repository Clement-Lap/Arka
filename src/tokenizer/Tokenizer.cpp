#include <stdexcept>
#include <iostream>

#include "Types.h"
#include "Tokenizer.h"

std::map<TokenTypes, std::string> TokenTypeNames = {
  {NumberLiteral, "NumberLiteral"},
  {Identifier, "Identifier"},
  {Equal, "Equal"},
  {Plus, "Plus"},
  {Minus, "Minus"},
  {Star, "Star"},
  {Slash, "Slash"},
  {A_Slash, "A_Slash"},
  {L_Paren, "L_Paren"},
  {R_Paren, "R_Paren"},
  {L_Bracket, "L_Bracket"},
  {R_Bracket, "R_Bracket"},
  {Semicol, "Semicolon"},
  {Colon, "Colon"},
  {Hashtag, "Hashtag"},
  {L_Angle_Bracket, "L_Angle_Bracket"},
  {R_Angle_Bracket, "R_Angle_Bracket"},
  {Quote, "Quote"},
  {D_Quote, "D_Quote"},
  {Dollar, "Dollar_Sign"},
  {Dot, "Dot"},
  {Comma, "Comma"},
};

void print_token(Token& tok)
{
  std::cout << "[" << tok.token_type << "; \"" << tok.lexem << "\"]";
}

std::vector<Token> Tokenizer::tokenize(std::string code)
{
  size_t pos = 0;
  std::vector<Token> result;
  for (;pos < code.length(); pos++)
  {
    char current_char = code.at(pos);

    if (isdigit(current_char))
    {
      std::string return_num(1, current_char);

      while (pos + 1 < code.length() && isdigit(code.at(pos + 1)))
      {
        pos++;
        return_num.push_back(code.at(pos));
      }

      result.push_back(Token{TokenTypes::NumberLiteral, return_num});
      continue;
    }

    if (isalpha(current_char))
    {
      std::string return_str(1, current_char);

      while (pos + 1 < code.length() && isalnum(code.at(pos + 1)))
      {
        pos++;
        return_str.push_back(code.at(pos));
      }

      result.push_back(Token{TokenTypes::Identifier, return_str});
      continue;
    }

    // ignore comments
    if (pos + 1 < code.length() && current_char == '/' && code.at(pos + 1) == '*')
    {
      pos += 2;
      while (pos + 1 < code.length() && !(code.at(pos) == '*' && code.at(pos + 1) == '/'))
      {
        pos++;
      }
      if (pos + 1 < code.length())
      {
        pos += 2;
      }
      continue;
    }

    //ignore single line comments
    if (pos + 1 < code.length() && current_char == '/' && code.at(pos + 1) == '/')
    {
      pos++;
      while (pos + 1 < code.length() && code.at(pos) != '\n')
      {
        pos++;
      }
      continue;
    }

    //check for symbols
    switch (current_char)
    {

    case SPACE: break;
    case ENDLINE: break;
    case TAB: break;

    case EQUAL: result.push_back(Token{Equal, std::string(1, current_char)});
      break;
    case SLASH: result.push_back(Token{Slash, std::string(1, current_char)});
      break;
    case PLUS: result.push_back(Token{Plus, std::string(1, current_char)});
      break;
    case MINUS: result.push_back(Token{Minus, std::string(1, current_char)});
      break;
    case STAR: result.push_back(Token{Star, std::string(1, current_char)});
      break;
    case L_PAR: result.push_back(Token{L_Paren, std::string(1, current_char)});
      break;
    case R_PAR: result.push_back(Token{R_Paren, std::string(1, current_char)});
      break;
    case L_BRAQ: result.push_back(Token{L_Bracket, std::string(1, current_char)});
      break;
    case R_BRAQ: result.push_back(Token{R_Bracket, std::string(1, current_char)});
      break;
    case SEMI_COLON: result.push_back(Token{Semicol, std::string(1, current_char)});
      break;
    case COLON: result.push_back(Token{Colon, std::string(1, current_char)});
      break;
    case HASHTAG: result.push_back(Token{Hashtag, std::string(1, current_char)});
      break;
    case L_ANGLE_BRA: result.push_back(Token{L_Angle_Bracket, std::string(1, current_char)});
      break;
    case R_ANGLE_BRA: result.push_back(Token{R_Angle_Bracket, std::string(1, current_char)});
      break;
    case QUOTE: result.push_back(Token{Quote, std::string(1, current_char)});
      break;
    case DOUBLE_QUOTE: result.push_back(Token{D_Quote, std::string(1, current_char)});
      break;
    case DOLLAR: result.push_back(Token{Dollar, std::string(1, current_char)});
      break;
    case DOT: result.push_back(Token{Dot, std::string(1, current_char)});
      break;
    case COMMA: result.push_back(Token{Comma, std::string(1, current_char)});
      break;
    case L_SQR_BRAQ: result.push_back(Token{L_Square_Bracket, std::string(1, current_char)});
      break;
    case R_SQR_BRAQ: result.push_back(Token{R_Square_Bracket, std::string(1, current_char)});
      break;
    case UNDERSCORE: result.push_back(Token{Underscore, std::string(1, current_char)});
      break;
    case VBAR: result.push_back(Token{Vertical_Bar, std::string(1, current_char)});
      break;

    default:
      std::cerr << "UNDEFINED Token: " << current_char << std::endl;
      result.push_back(Token{UNDEFINED, std::string(1, current_char)});
      break;
    }
  }

  return result;
}