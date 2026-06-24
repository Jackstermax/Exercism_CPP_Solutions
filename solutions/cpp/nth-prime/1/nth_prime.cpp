#include "nth_prime.h"

namespace nth_prime {
bool is_prime(int num) {    
    if (num <= 1)  { return false; }
    for (int i {2}; std::pow(i,2) <= num; ++i) {
        if  (num % i == 0) { return false; }
    }
    return true;
}    
int nth(int n) {
    if (n == 0) { throw std::domain_error("Error: Invalid Prime Number Index."); }

    int count {0}, num_primes {0};
    while (num_primes < n) {
        ++count;
        if (is_prime(count)) { ++num_primes; }
    }
    return count;
}
}  // namespace nth_prime
