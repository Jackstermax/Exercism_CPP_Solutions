#ifndef KINDERGARTEN_GARDEN_H
#define KINDERGARTEN_GARDEN_H

#include <string>
#include <array>
#include <vector>
#include <unordered_map>

#include <sstream>
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include <iterator>

namespace kindergarten_garden {
static const int pots_per_row {2}; 
static const std::vector<std::string> class_list {"Alice", "Bob", "Charlie", "David", "Eve", "Fred", "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"};
    
enum class Plants {    
    clover,
    grass,
    violets,
    radishes    
};

static const std::unordered_map<char, Plants> plants_dict {
{'C', Plants::clover},
{'G', Plants::grass},
{'V', Plants::violets},
{'R', Plants::radishes}
};

std::array<Plants, 4> plants(const std::string& rows, const std::string& name);
}  // namespace kindergarten_garden
#endif