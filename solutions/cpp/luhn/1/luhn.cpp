#include "luhn.h"

namespace luhn {
std::string format_input(std::string input) {
    input.erase(std::remove_if(input.begin(), input.end(), 
        [](char c) { return std::isspace(c); }),
        input.end()); // Leave only numbers, makes things easier
    std::reverse(input.begin(), input.end()); // Reverse for consistent indexing between SIN & Credit Card Numbers
    return input;
}    
bool valid(const std::string& str) {
    std::string input {format_input(str)};    
    if (input.size() <= 1) { return false; }
    if (any_of(input.begin(), input.end(), [](char c) { return !std::isdigit(c); })) { return false ;}  
    int sum {0};
    for (std::size_t i {0}; i < input.size(); ++i) {        
        int num {(input[i] - '0')};        
        if (i % 2 != 0) {             
            num *= 2;
            if (num > 9) { num -= 9; }            
        }        
        sum += num;
    }

    return sum % 10 == 0;
}
}  // namespace luhn