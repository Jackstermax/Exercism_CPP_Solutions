#include "sum_of_multiples.h"

namespace sum_of_multiples {
int to(const std::vector<int>& item_vals, const int level)    {
    if (item_vals.size() <= 0) { return 0; }
    
    std::set<int> values {};
    for (int x : item_vals)    {
        int i {1}; 
        while (x * i < level) { values.insert(x * i); ++i; }
    }    
    return std::accumulate(values.begin(), values.end(), 0);
}
}  // namespace sum_of_multiples