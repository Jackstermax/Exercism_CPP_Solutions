#include "sieve.h"

namespace sieve {
bool is_prime(int num) {
    if (num <= 1) { return false; }
    for (int i{2}; std::pow(i,2) <= num; ++i) {
        if (num % i == 0) { return false; }
    }
    return true;
}

std::vector<int> primes(int num) {
    std::vector<int> numbers {};
    for (int i {2}; i <= num; ++i) {
        if (!is_prime(i)) { continue; }
        numbers.emplace_back(i);
    }
    return numbers;
}
}  // namespace sieve