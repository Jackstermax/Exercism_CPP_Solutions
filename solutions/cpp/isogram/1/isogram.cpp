#include "isogram.h"

namespace isogram {
bool is_isogram(const std::string& str) {
    if (str.empty()) { return true; }
    
    std::unordered_map<char, int> letters {};
    for (char c : str) {
        if (!std::isalpha(c)) { continue; } 
        char c_low = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        ++letters[c_low];
    }
    auto iter = std::find_if(letters.begin(), letters.end(), [](const std::pair<char, int>& pair) {return pair.second > 1;});
    return iter == letters.end();
}
}  // namespace isogram