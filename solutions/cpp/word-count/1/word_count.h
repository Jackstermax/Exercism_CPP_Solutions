#pragma once
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <cctype>
namespace word_count {
std::string& normalize_text(std::string& str);
std::map<std::string, int> words(const std::string& sentc);
}  // namespace word_count