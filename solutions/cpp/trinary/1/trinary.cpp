#include "trinary.h"

namespace trinary {
int to_decimal(const std::string& bin) {
    std::string reversed {bin};
    std::reverse(reversed.begin(), reversed.end());
    
    int total {0};
    for (std::size_t i {0}; i < reversed.size() ; ++i)   {
        if (!(std::isdigit(reversed[i]))) { return 0; }
        
        int char_int { reversed[i] - '0' };        
        total += char_int * static_cast<int>(std::pow(3, i));
    }
    return total;
}
}  // namespace trinary