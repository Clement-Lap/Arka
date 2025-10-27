#ifndef ARKA_AST_H
#define ARKA_AST_H

#include "../../tokenizer/Tokenizer.h"


class AST
{
public:
  size_t tok_size;


  void consume_token(Token tok[])
  {
  }

private:
  struct parsed_tokens : Token
  {
  };
};

#endif //ARKA_AST_H