#include "binary.h"

namespace binary {
int convert(const std::string& num) {    
    int sum {0};
    int bin_pow {1};
    if (num.empty()) { return 0; }
    
    for (int i = num.size() - 1; i >= 0; --i) {
        char c {num[i]};
        if (c < '0' || c > '1') { return 0; }
        if (c == '1') { sum += bin_pow; }   
        bin_pow *= 2; // Increase for each subsequent column
    }
    return sum;
}
}  // namespace binary