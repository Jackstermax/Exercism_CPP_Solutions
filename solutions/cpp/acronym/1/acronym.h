#pragma once
#include<string>
#include <sstream>
#include <algorithm>
#include <cctype>
namespace acronym {
std::string format_input(std::string str);
std::string acronym(const std::string& input);
}  // namespace acronym