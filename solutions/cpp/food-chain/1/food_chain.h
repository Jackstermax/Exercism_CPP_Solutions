#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
namespace food_chain {  
struct suffix_info
{
    std::string suffix {};
    bool always_print {false};
};
    
static const std::vector<std::pair<std::string, suffix_info>> lyrics {
    {"horse",  {"She's dead, of course!", true}},
    {"cow",    {"I don't know how she swallowed a cow!"}},  
    {"goat",   {"Just opened her throat and swallowed a goat!"}},
    {"dog",    {"What a hog, to swallow a dog!"}},
    {"cat",    {"Imagine that, to swallow a cat!"}},    
    {"bird",   {"How absurd to swallow a bird!"}},
    {"spider", {"It wriggled and jiggled and tickled inside her.", true}}, 
    {"fly",    {"I don't know why she swallowed the fly. Perhaps she'll die.", true}}
};
std::string verse(int startNum);
std::string verses(int startNum, int endNum);
std::string sing();
}  // namespace food_chain