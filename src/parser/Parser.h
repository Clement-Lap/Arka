#ifndef ARKA_PARSER_H
#define ARKA_PARSER_H

#include "AST/AST.h"

#include <vector>
#include <variant>
#include <iostream>
#include <cstdint>


class Declaration
{
public:
    void print();
    void push(const Token& tok);
    void clear();
    std::vector<Token> get_declaration() const;

private:
    std::vector<Token> m_Action;
};

class Scope
{
public:
    void print(uint8_t& tab);
    void push(Declaration decl);
    void push(Scope scope);
    void clear();
    std::vector<std::variant<Declaration, Scope>> get_scope() const;

private:
    std::vector<std::variant<Declaration, Scope>> m_Scope;
};

class Program
{
public:
    void print();
    void push(const Scope& scope);
    void clear_program();
    std::vector<Scope> get_program() const;

private:
    std::vector<Scope> m_Program;
};

class Parser
{
public:
    void parse(std::vector<Token>& tokens); //idk for now

    Program identify_tokens(std::vector<Token> tok); // 1 vector<vector<Token>> = a scope, split vector<Token> with ";"

    void merge_token(const std::vector<Token>& tok); // detect what the vector is about (var, func...)

    void consume_token(const Token& tok); // add token to the AST


private:
    AST tree;
};

/*
struct Type {

    struct Program {
        std::string name;
        uint start;
        uint end;
    };

    struct Body {

    };

    struct Expression {
        std::string type;
        std::string identifier;
        uint start;
        uint end;
    };

    struct Function {
        std::string name;
        std::string return_type;
        int parameters_num;
        std::list<Type::Expression> parameters;
    };

    struct Classes {
        std::string name;
    };

    typedef struct Preprocess {
        std::string type;
        std::string args[];
    };
};
*/


#endif //ARKA_PARSER_H
