#include "hexadecimal.h"

namespace hexadecimal {
    int convert_char(char c) {
        c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        if (c >= '0' && c <= '9') { return (c - '0'); }            
        if (c >= 'A' && c <= 'F') { return (c - 'A' + 10); }   
        return -1;
    }    
    int convert(const std::string& num_str) {
        int sum {0};
        for (std::size_t i {0}; i < num_str.size(); ++i) {            
            int val {convert_char(num_str[i])};
            if (val < 0) { return 0; }
            sum = (sum * 16) + val;
        }
        return sum;
    }   
}  // namespace hexadecimal