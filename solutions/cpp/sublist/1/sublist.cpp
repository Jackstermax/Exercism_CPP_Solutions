#include "sublist.h"

namespace sublist {
bool compare_lists(const std::vector<int>& x, const std::vector<int>& y) {
    for (std::size_t i {0}; i < y.size(); ++i) {
        if (std::equal(x.begin(), x.end(), y.begin() + i)) { return true; }
    }
    return false;
}

List_comparison sublist(const std::vector<int>& x, const std::vector<int>& y) {
    std::size_t size_x {x.size()};
    std::size_t size_y {y.size()};

    if (size_x > size_y) { return compare_lists(y, x) ? List_comparison::superlist : List_comparison::unequal; }
    if (size_x < size_y) { return compare_lists(x, y) ? List_comparison::sublist : List_comparison::unequal;   }
    return x == y ? List_comparison::equal : List_comparison::unequal;
}
}  // namespace sublist