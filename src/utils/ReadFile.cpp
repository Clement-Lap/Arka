#include "ReadFile.h"

std::string read_file(std::fstream& FILE)
{
  std::string full_string;
  if (!FILE.is_open())
  {
    std::cerr << "Failed to open file." << std::endl;
    return "";
  }
  else
  {
    std::string buffer;
    while (std::getline(FILE, buffer))
    {
      full_string.append(buffer);
    }
  }
  FILE.close();
  return full_string;
};

std::vector<Token> read_lines_tokenize(std::fstream& FILE, Tokenizer tokenizer)
{
  std::vector<Token> result;
  if (!FILE.is_open())
  {
    std::cerr << "Error when opening file" << std::endl;
  }
  else
  {
    std::string buffer;
    while (std::getline(FILE, buffer))
    {
      if (!buffer.empty() || buffer != "\n")
      {
        std::vector<Token> temp = tokenizer.tokenize(buffer);
        buffer.clear();
        if (!temp.empty())
        {
          for (Token t : temp)
          {
            result.push_back(t);
          }
          temp.clear();
        }
      }
    }
  }
  FILE.close();
  return result;
};

void test()
{
  std::cout << "testing nice" << std::endl;
}