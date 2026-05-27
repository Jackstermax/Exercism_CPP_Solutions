#pragma once
#include <string>
#include <cctype>
#include <algorithm>
namespace atbash_cipher {

static constexpr int max_chars_grouped = 5;
static constexpr char skip_marker = '\0';
    
char convert_char (char c);
std::string encode(const std::string& str);
std::string decode(const std::string& str);
}  // namespace atbash_cipher