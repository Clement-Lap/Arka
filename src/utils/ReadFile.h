#ifndef ARKA_UTILS_READFILE_H
#define ARKA_UTILS_READFILE_H

#include <fstream>
#include <iostream>
#include <vector>
#include "../tokenizer/Tokenizer.h"

std::string read_file(std::fstream & FILE);
std::vector<Token> read_lines_tokenize(const std::fstream& FILE, Tokenizer tokenizer);
void test();

#endif //ARKA_UTILS_READFILE_H
