#include "grains.h"

namespace grains {
    long long unsigned int square(int square_num)  {
        if (square_num <= 0 && square_num > 64) { throw std::out_of_range("Error: Number must be between 1 and 64!"); }
        return std::pow(2, square_num - 1); // 2^n-1 for the grains gained on that specific day
    }
    long long unsigned int total()  {
        long long unsigned int square_total { 0 };
        for (int i{ 1 }; i <= 64; ++i)
            square_total += square(i);        
        return square_total;
    }
}  // namespace grains