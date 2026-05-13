#include "hamming.h"

namespace hamming {
int compute(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) { throw std::domain_error("Strands cannot be empty, or of different lengths"); }

    int diff_count{0};
    for (std::size_t i {0}; i < a.size(); ++i)  {
        if (a.at(i) !=  b.at(i)) { ++diff_count; }    
    }    
    return diff_count;
}
}  // namespace hamming
