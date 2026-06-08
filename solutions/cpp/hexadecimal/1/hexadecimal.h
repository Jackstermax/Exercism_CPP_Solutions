#pragma once
#include <string>
#include <cctype>
#include <cmath>
#include <algorithm>
namespace hexadecimal {
int convert_char(char c);
int convert(const std::string& num_str);
}  // namespace hexadecimal