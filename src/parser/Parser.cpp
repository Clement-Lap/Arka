#include "Parser.h"
#include <stack>

void Parser::parse(std::vector<Token>& tokens) {

}

Program Parser::identify_tokens(std::vector<Token> tok)
{
    Program program;
    std::stack<Scope> scope;
    Declaration declaration;

    bool is_string_scope = false;

    scope.emplace();

    for (size_t pos = 0; pos < tok.size(); pos++)
    {
        Token curr = tok.at(pos);
        switch (curr.token_type)
        {
        case TokenTypes::Semicol:
            if (!declaration.get_declaration().empty())
            {
                scope.top().push(declaration);
                declaration.clear();
            }
            break;

        case TokenTypes::L_Bracket:
            if (tok.at(pos-1).token_type == TokenTypes::Dollar)
            {
                is_string_scope = true;
                break;
            };
            scope.emplace();

            break;

        case TokenTypes::R_Bracket:
            {
                if (is_string_scope) break;
                if (!declaration.get_declaration().empty()) {
                    scope.top().push(declaration);
                    declaration.clear();
                }

                Scope inner = scope.top();
                scope.pop();
                scope.top().push(inner);
                break;
            }

        default:
            declaration.push(curr);
            break;
        }
    }

    if (scope.size() > 1)
    {
        std::cerr << "missing curly braces : '}'" << std::endl;
        exit(1);
    }

    program.push(scope.top());

    return program;
}

void Parser::merge_token(const std::vector<Token>& tok)
{
}

void Parser::consume_token(const Token& tok)
{
}

void Scope::push(Scope scope)
{
    m_Scope.push_back(scope);
}

void Scope::push(Declaration decl)
{
    m_Scope.push_back(decl);
}

std::vector<std::variant<Declaration, Scope>> Scope::get_scope() const
{
    return m_Scope;
}

void Scope::clear()
{
    m_Scope.clear();
}

void Program::push(const Scope& scope)
{
    m_Program.push_back(scope);
}

std::vector<Scope> Program::get_program() const
{
    return m_Program;
}

void Program::clear_program()
{
    m_Program.clear();
}

void Declaration::push(const Token& tok)
{
    m_Action.push_back(tok);
}

std::vector<Token> Declaration::get_declaration() const
{
    return m_Action;
}

void Declaration::clear()
{
    m_Action.clear();
}

void Declaration::print()
{
    for (auto& tok : m_Action)
    {
        print_token(tok);
        std::cout << " ";
    }
    std::cout << std::endl;
}

void Scope::print(uint8_t& tab)
{
    for (auto& elem : m_Scope)
    {
        if (auto decl = std::get_if<Declaration>(&elem))
        {
            decl->print();
        }
        else if (auto scope = std::get_if<Scope>(&elem))
        {
            std::cout << "SCOPE" << std::endl;
            scope->print(tab);
            std::cout << "END OF SCOPE" << std::endl;
        }
    }
}

void Program::print()
{
    uint8_t tab;
    for (auto& scope : m_Program)
    {
        scope.print(tab);
    }
}
