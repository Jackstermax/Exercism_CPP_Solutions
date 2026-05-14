#include "difference_of_squares.h"

namespace difference_of_squares {
int square_of_sum(int x) {
    int sum {0};
    for (int i {1}; i <= x; ++i)
        { sum += i; }
    return std::pow(sum, 2);
}
int sum_of_squares(int x) {
    int sum {0};
    for (int i {1}; i <= x; ++i)
        { sum += std::pow(i, 2); }
    return sum;
}
int difference(int x) {
    return std::abs(square_of_sum(x) - sum_of_squares(x));
}
}  // namespace difference_of_squares