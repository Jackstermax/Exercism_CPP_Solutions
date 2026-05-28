#pragma once
#include <algorithm>
#include <string>
namespace beer_song {
static constexpr int max_bottles_from_da_liqa_sto = 99;
std::string& replace_value(std::string& phrase, const std::string& target, const std::string& value);
std::string verse(const int verse_num);
std::string sing(const int start, const int end = 0);
}  // namespace beer_song