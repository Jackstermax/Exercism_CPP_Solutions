#include "armstrong_numbers.h"

namespace armstrong_numbers {
bool is_armstrong_number(int num) {
    std::string num_str {std::to_string(num)};

    int total{0}, counter{static_cast<int>(num_str.size())};
    for (char c : num_str) {
        int dig {c - '0'};
        total += (std::pow(dig, counter));        
    }
    return total == num;
}
}  // namespace armstrong_numbers