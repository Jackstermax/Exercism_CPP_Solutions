#include "resistor_color.h"

namespace resistor_color {
int color_code(const std::string& colour) {
    auto iter = std::find_if(colour_vals.begin(), colour_vals.end(), [colour](const auto& pair) {return pair.second == colour;});
    if (iter == colour_vals.end()) { return -1; }
    return iter->first;
}
std::vector<std::string> colors() {
    std::vector<std::string> col_list {};
    for (const auto& [key, value] : colour_vals) {
        col_list.emplace_back(value);
    }
    return col_list;
}
}  // namespace resistor_color