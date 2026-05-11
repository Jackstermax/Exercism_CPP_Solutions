#ifndef TRIANGLE_H
#define TRIANGLE_H
    
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdexcept>

namespace triangle {
    enum class flavor
    {
    equilateral,
    isosceles,
    scalene    
    };

    bool is_equilateral(float x, float y, float z);
    bool is_isosceles(float x, float y, float z);
    flavor kind(float a, float b, float c); 
}  // namespace triangle
#endif