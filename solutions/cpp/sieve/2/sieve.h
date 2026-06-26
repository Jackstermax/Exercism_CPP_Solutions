#ifndef SIEVE_H
#define SIEVE_H

#include <cmath>
#include <vector>
#include <algorithm>
namespace sieve {
bool is_prime(int num);
std::vector<int> primes(int num);
}  // namespace sieve
#endif