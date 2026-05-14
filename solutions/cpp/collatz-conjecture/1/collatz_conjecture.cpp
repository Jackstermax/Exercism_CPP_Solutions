#include "collatz_conjecture.h"

namespace collatz_conjecture {
int steps(int amt) {
    if (amt <= 0) { throw std::domain_error("Starting point cannot be below 1."); }       
    int steps{0};
    while (amt != 1)  {
        if (amt % 2 != 0) { amt = (amt * 3) + 1; }
        else              { amt /= 2; }
        ++steps;
    }
    return steps;
}
}  // namespace collatz_conjecture