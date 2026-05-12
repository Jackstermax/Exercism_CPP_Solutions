#include "pangram.h"

namespace pangram {
bool is_pangram(const std::string& str) {
    if (str.empty()) { return false; } // If empty, it has nothing to test, so it fails.
    
    // Converts input to all lowercase for convenience.
    std::string str_lower {str};
    std::transform(str_lower.begin(), str_lower.end(), str_lower.begin(),[](unsigned char c){ return std::tolower(c); });     
    
    for(char i {'a'}; i <= 'z'; ++i)  {
        if (str_lower.find(i) == std::string::npos) { return false; } // If we reach end marker of the string, we didn't find it; break.
    }
    return true;
}
}  // namespace pangram