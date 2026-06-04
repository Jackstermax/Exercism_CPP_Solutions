#pragma once
#include <string>          
#include <algorithm>  

namespace luhn {
std::string format_input(std::string input);
bool valid(const std::string& str);
}  // namespace luhn