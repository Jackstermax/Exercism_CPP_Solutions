#pragma once
#include <stack>
#include <map>
#include <algorithm>
#include <string>
#include <cctype>

namespace matching_brackets {
static const std::map<char,char> brackets {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}
};
bool check(const std::string& str);
}  // namespace matching_brackets