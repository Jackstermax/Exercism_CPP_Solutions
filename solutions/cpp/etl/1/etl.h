#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
namespace etl {
std::map<char, int> transform(const std::map<int, std::vector<char>>& input);
}  // namespace etl