#include "etl.h"

namespace etl {
std::map<char, int> transform(const std::map<int, std::vector<char>>& input)    {
    std::map<char, int> output {};
    for (const auto& [key, value] : input) {
        for (char c : value) {            
            char c_lower {static_cast<char>(std::tolower(static_cast<unsigned char>(c)))};
            if (output.find(c_lower) != output.end()) { continue; }
            output.insert({c_lower, key});
        }        
    }
    return output;
}
}  // namespace etl