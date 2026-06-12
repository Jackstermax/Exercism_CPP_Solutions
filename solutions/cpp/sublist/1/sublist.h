#pragma once
#include <vector>
#include <algorithm>

namespace sublist {
enum class List_comparison { equal, sublist, superlist, unequal };       
bool compare_lists(const std::vector<int>& x, const std::vector<int>& y);
List_comparison sublist(const std::vector<int>& x, const std::vector<int>& y);
}  // namespace sublist
