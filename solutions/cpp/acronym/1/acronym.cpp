#include "acronym.h"

namespace acronym {
std::string format_input(std::string str) {
    std::replace(str.begin(), str.end(), '-', ' ');
    std::replace(str.begin(), str.end(), '_', ' ');
    std::transform(str.begin(), str.end(), str.begin(), 
    [](unsigned char c)
    { return static_cast<char>(std::toupper(c)); });
    return str;
}
std::string acronym(const std::string& input) {
    std::string str {format_input(input)};   

    std::string result {};
    std::string word {};
    std::stringstream s_str {str};
    while (s_str >> word) {
        if (!std::isalpha(static_cast<unsigned char>(word[0]))) { continue; }
        result.push_back(word[0]);
    }
    return result;
}
}  // namespace acronym