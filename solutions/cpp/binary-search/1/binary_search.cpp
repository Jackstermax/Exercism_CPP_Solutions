#include "binary_search.h"

namespace binary_search {

std::size_t find(std::vector<int> list, int target) {
    if (list.empty()) { throw std::domain_error("Error: List is empty, yeet!"); }
    std::sort(list.begin(), list.end()); // Make sure we're all sorted, ascending :)
    
    int min {0}, max {static_cast<int>(list.size()-1)};
     while (min <= max) {
        int mid { min + ((max-min)/2)};
        if (list[mid] == target)     { return mid;  }
        else if (list[mid] > target) { max = mid-1; }
        else                         { min = mid+1; }
    }  
    throw std::domain_error("Error: Target not found in list");
}    
}  // namespace binary_search