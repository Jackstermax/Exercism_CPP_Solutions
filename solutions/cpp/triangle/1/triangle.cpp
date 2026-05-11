#include "triangle.h"

namespace triangle {    
    // Made this function to make the equilateral check cleaner, but could be done without
    bool is_equilateral(float x, float y, float z) { return (x == y && x == z); }
    // Made this function to make the isosceles check cleaner, but could be done without
    bool is_isosceles  (float x, float y, float z) { return (x == y && x != z) || (x != y && y == z); }
    
    flavor kind(float a, float b, float c) {        
        std::vector<float> sides { a, b, c };
        std::sort(sides.begin(), sides.end(), [](float x, float y) { return x < y; }); // Sort sides, ascending order, for convenience.
        if (std::any_of(sides.begin(), sides.end(), [](float f) { return f <= 0; })) { throw std::domain_error("ERROR: Triangle has sides equal/less-than 0 in length!"); }
        
        if (is_equilateral(sides[0], sides[1], sides[2])) { return flavor::equilateral; }
        // If we get here, we are checking for the triangle rule for non-equilateral triangles. Because we ordered them above, we only need to check one permutation of the rule.
        if (sides[0] + sides[1] < sides[2]) {  throw std::domain_error("ERROR: Triangle violates triangle side inequality rule!"); }
        // Then we just differ between isosceles and scalene   
        if (is_isosceles(sides[0], sides[1], sides[2])) { return flavor::isosceles; }                
        else { return flavor::scalene; }        
     }
}  // namespace triangle