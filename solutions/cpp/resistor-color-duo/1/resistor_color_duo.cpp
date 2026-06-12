#include "resistor_color_duo.h"

namespace resistor_color_duo {
int color_code(const std::string& colour) {
    auto iter = std::find_if(colour_vals.begin(), colour_vals.end(), [colour](const auto& pair) {return pair.second == colour;});
    if (iter == colour_vals.end()) { return -1; }
    return iter->first;
}
int value(const std::vector<std::string>& colours) {
    if (colours.empty()) { return 0; }    
    std::vector<std::string> duo_band { colours };
    duo_band.resize(2);
    std::reverse(duo_band.begin(), duo_band.end());

    int result {0};
    for (std::size_t i {0}; i < duo_band.size(); ++i) {
        int val {color_code(duo_band[i])};
        if (val <= 0) { continue; }
        result += val * std::pow(10,i);
    }
    return result;
}        
}  // namespace resistor_color_duo